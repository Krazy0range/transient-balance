#include <stdio.h>
#include <string.h>

#include "weather.h"
#include "utils.h"

weather_data *load_file_weather(FILE *json_file)
{
    cJSON *json_root;

    char *json_raw = file_to_string(json_file);
    json_root = cJSON_Parse(json_raw);
    free(json_raw);

    return load_json_weather_data(json_root);
}

weather_data *load_json_weather_data(cJSON *json_root)
{
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

    /* top level data */

    cJSON *json_latitude;
    cJSON *json_longitude;
    cJSON *json_elevation;
    cJSON *json_timezone;
    cJSON *json_timezone_abbreviation;

    json_latitude = cJSON_GetObjectItem(json_root, "latitude");
    json_longitude = cJSON_GetObjectItem(json_root, "longitude");
    json_elevation = cJSON_GetObjectItem(json_root, "elevation");
    json_timezone = cJSON_GetObjectItem(json_root, "timezone");
    json_timezone_abbreviation = cJSON_GetObjectItem(json_root, "timezone_abbreviation");

    _set_weather_data_num(&data->latitude, json_latitude);
    _set_weather_data_num(&data->longitude, json_longitude);
    _set_weather_data_num(&data->elevation, json_elevation);
    _set_weather_data_str(&data->timezone, json_timezone);
    _set_weather_data_str(&data->timezone_abbreviation, json_timezone_abbreviation);

    /* current_units data */

    cJSON *json_current_units;
    cJSON *json_current;
    cJSON *json_hourly_units;
    cJSON *json_hourly;
    cJSON *json_daily_units;
    cJSON *json_daily;
    
    json_current_units = cJSON_GetObjectItem(json_root, "current_units");
    json_current = cJSON_GetObjectItem(json_root, "current");
    json_hourly_units = cJSON_GetObjectItem(json_root, "hourly_units");
    json_hourly = cJSON_GetObjectItem(json_root, "hourly");
    json_daily_units = cJSON_GetObjectItem(json_root, "daily_units");
    json_daily = cJSON_GetObjectitem(json_root, "daily");
    
    load_json_weather_current_units(json_current_units);
    load_json_weather_current(json_current);
    load_json_weather_hourly_units(json_hourly_units);
    load_json_weather_hourly(json_hourly);
    load_json_weather_daily_units(json_daily_units);
    load_json_weather_daily(json_daily);

    // TODO this is extremely temporary, this memory needs to be freed!
    // cJSON_Delete(json_root);

    return data;
}

void _set_weather_data_num(double **dest, cJSON *json_src)
{
    if (cJSON_IsNumber(json_src))
        *dest = (double *) &json_src->valuedouble;
}

void _set_weather_data_str(char **dest, cJSON *json_src)
{
    if (cJSON_IsString(json_src))
        *dest = (char *) json_src->valuestring;
}