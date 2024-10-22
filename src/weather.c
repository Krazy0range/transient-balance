#include <stdio.h>

#include "cJSON/cJSON.h"

#include "weather.h"
#include "utils.h"

weather_data *load_weather(FILE *file)
{
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

    fprintf(stderr, "loading weather data\n");

    cJSON_Delete(json_root);

    return NULL;
}