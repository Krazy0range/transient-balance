#include <stdio.h>
#include <string.h>

#include "cJSON/cJSON.h"

#include "weather.h"
#include "utils.h"

weather_data *load_weather(FILE *file)
{
    /* load json from file */

    char *json_raw = file_to_string(file);

    cJSON *json_root = cJSON_Parse(json_raw);

    free(json_raw);

    if (json_root == NULL)
    {
        const char *err = cJSON_GetErrorPtr();
        fprintf(stderr, "cJSON error: %s", err);
        cJSON_Delete(json_root);
        return NULL;
    }

    /* file out weather data struct */

    weather_data *data;
    data = malloc(sizeof(weather_data));

    fprintf(stderr, "loading weather data\n");

    // TODO
    // TODO
    /*
     * weather_data creation struct? smth like weather_data_create???
     * pointers to json strings and stuff, and then call smth like
     * create_weather_data(weather_data *, weather_data_create *)
     * to handle all the allocation and string copies seperately
     *      much poggers! like vulcan lol
     *      encapsulation == good
     *      clean code == good
     *      LOTS OF SATISFYING AESTHETIC CODE == sooo gooood
     * 
     * also, we need optional fields for everything
     * change all the floats to float *, all the strings are fine
     * 
     * make weather creation data structs, and make weather
     * creation and deletion functions
     * 
     * omg this is sooo poggers
     */
    // TODO
    // TODO

    cJSON *json_latitude;
    cJSON *json_longitude;
    cJSON *json_timezone;
    cJSON *json_timezone_abbreviation;
    cJSON *json_elevation;

    json_latitude = cJSON_GetObjectItem(json_root, "latitude");
    json_longitude = cJSON_GetObjectItem(json_root, "longitude");
    json_timezone = cJSON_GetObjectItem(json_root, "timezone");
    json_timezone_abbreviation = cJSON_GetObjectItem(json_root, "timezone_abbreviation");
    json_elevation = cJSON_GetObjectItem(json_root, "elevation");

    if (json_latitude && json_latitude->type == cJSON_Number)
        data->latitude = (float) json_latitude->valuedouble;
    
    if (json_longitude && json_longitude->type == cJSON_Number)
        data->longitude = (float) json_longitude->valuedouble;
    
    if (json_timezone && json_timezone->type == cJSON_String)
    {
        data->timezone = malloc(strlen(json_timezone->valuestring));
        strcpy(data->timezone, json_timezone->valuestring);
    }

    if (json_timezone_abbreviation && json_timezone_abbreviation->type == cJSON_String)
    {
        data->timezone_abbreviation = malloc(strlen(json_timezone_abbreviation->valuestring));
        strcpy(data->timezone_abbreviation, json_timezone_abbreviation->valuestring);
    }

    if (json_elevation && json_elevation->type == cJSON_Number)
        data->elevation = json_elevation->valueint;
    
    data->current_units = NULL;
    data->current = NULL;
    data->hourly_units = NULL;
    data->hourly = NULL;
    data->daily_units = NULL;
    data->daily = NULL;

    cJSON_Delete(json_root);

    return data;
}