#include <stdio.h>
#include <string.h>

#include "weather.h"
#include "utils.h"

/* helpers */

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

void _create_weather_num(double **dest, double *src)
{
    if (src == NULL)
        return;

    *dest = malloc(sizeof(double));
    **dest = *src;
}

void _create_weather_str(char **dest, char *src)
{
    if (src == NULL)
        return;

    uint16_t len = strlen(src) + 1;
    *dest = malloc(sizeof(char) * len);
    strncpy(*dest, src, len);
}

/* create weather */

void create_weather_data(weather_data **dest, weather_data *src)
{
    *dest = malloc(sizeof(weather_data));

    _create_weather_num(&(*dest)->latitude, src->latitude);
    _create_weather_num(&(*dest)->longitude, src->longitude);
    _create_weather_num(&(*dest)->elevation, src->elevation);
    _create_weather_str(&(*dest)->timezone, src->timezone);
    _create_weather_str(&(*dest)->timezone_abbreviation, src->timezone_abbreviation);

    create_weather_current_units(&(*dest)->current_units, src->current_units);
    create_weather_current(&(*dest)->current, src->current);
    create_weather_hourly_units(&(*dest)->hourly_units, src->hourly_units);
    create_weather_hourly(&(*dest)->hourly, src->hourly);
    create_weather_daily_units(&(*dest)->daily_units, src->daily_units);
    create_weather_daily(&(*dest)->daily, src->daily);
}

void create_weather_current_units(weather_current_units **dest, weather_current_units *src)
{
    if (src == NULL)
        return;
    
    *dest = malloc(sizeof(* dest));

    _create_weather_str(&(*dest)->time, src->time);
    _create_weather_str(&(*dest)->interval, src->interval);
    _create_weather_str(&(*dest)->temperature_2m, src->temperature_2m);
    _create_weather_str(&(*dest)->relative_humidity_2m, src->relative_humidity_2m);
    _create_weather_str(&(*dest)->apparent_temperature, src->apparent_temperature);
    _create_weather_str(&(*dest)->is_day, src->is_day);
    _create_weather_str(&(*dest)->precipitation, src->precipitation);
    _create_weather_str(&(*dest)->rain, src->rain);
    _create_weather_str(&(*dest)->showers, src->showers);
    _create_weather_str(&(*dest)->snowfall, src->snowfall);
    _create_weather_str(&(*dest)->weather_code, src->weather_code);
    _create_weather_str(&(*dest)->cloud_cover, src->cloud_cover);
    _create_weather_str(&(*dest)->pressure_msl, src->pressure_msl);
    _create_weather_str(&(*dest)->surface_pressure, src->surface_pressure);
    _create_weather_str(&(*dest)->wind_speed_10m, src->wind_speed_10m);
    _create_weather_str(&(*dest)->wind_direction_10m, src->wind_direction_10m);
    _create_weather_str(&(*dest)->wind_gusts_10m, src->wind_gusts_10m);
}

void create_weather_current(weather_current **dest, weather_current *src)
{
    if (src == NULL)
        return;

    *dest = malloc(sizeof(weather_current));

    _create_weather_num(&(*dest)->time, src->time);
    _create_weather_num(&(*dest)->interval, src->interval);
    _create_weather_num(&(*dest)->temperature_2m, src->temperature_2m);
    _create_weather_num(&(*dest)->relative_humidity_2m, src->relative_humidity_2m);
    _create_weather_num(&(*dest)->apparent_temperature, src->apparent_temperature);
    _create_weather_num(&(*dest)->is_day, src->is_day);
    _create_weather_num(&(*dest)->precipitation, src->precipitation);
    _create_weather_num(&(*dest)->rain, src->rain);
    _create_weather_num(&(*dest)->showers, src->showers);
    _create_weather_num(&(*dest)->snowfall, src->snowfall);
    _create_weather_num(&(*dest)->weather_code, src->weather_code);
    _create_weather_num(&(*dest)->cloud_cover, src->cloud_cover);
    _create_weather_num(&(*dest)->pressure_msl, src->pressure_msl);
    _create_weather_num(&(*dest)->surface_pressure, src->surface_pressure);
    _create_weather_num(&(*dest)->wind_speed_10m, src->wind_speed_10m);
    _create_weather_num(&(*dest)->wind_direction_10m, src->wind_direction_10m);
    _create_weather_num(&(*dest)->wind_gusts_10m, src->wind_gusts_10m);
}

void create_weather_hourly_units(weather_hourly_units **dest, weather_hourly_units *src)
{
    if (src == NULL)
        return;
        
    *dest = malloc(sizeof(weather_hourly_units));

    _create_weather_str(&(*dest)->time, src->time);
    _create_weather_str(&(*dest)->temperature_2m, src->temperature_2m);
    _create_weather_str(&(*dest)->relative_humidity_2m, src->relative_humidity_2m);
    _create_weather_str(&(*dest)->dew_point_2m, src->dew_point_2m);
    _create_weather_str(&(*dest)->apparent_temperature, src->apparent_temperature);
    _create_weather_str(&(*dest)->precipitation_probability, src->precipitation_probability);
    _create_weather_str(&(*dest)->precipitation, src->precipitation);
    _create_weather_str(&(*dest)->rain, src->rain);
    _create_weather_str(&(*dest)->showers, src->showers);
    _create_weather_str(&(*dest)->snowfall, src->snowfall);
    _create_weather_str(&(*dest)->snow_depth, src->snow_depth);
    _create_weather_str(&(*dest)->weather_code, src->weather_code);
    _create_weather_str(&(*dest)->pressure_msl, src->pressure_msl);
    _create_weather_str(&(*dest)->surface_pressure, src->surface_pressure);
    _create_weather_str(&(*dest)->cloud_cover, src->cloud_cover);
    _create_weather_str(&(*dest)->cloud_cover_low, src->cloud_cover_low);
    _create_weather_str(&(*dest)->cloud_cover_mid, src->cloud_cover_mid);
    _create_weather_str(&(*dest)->cloud_cover_high, src->cloud_cover_high);
    _create_weather_str(&(*dest)->visibility, src->visibility);
    _create_weather_str(&(*dest)->evapotranspiration, src->evapotranspiration);
    _create_weather_str(&(*dest)->et0_fao_evapotranspiration, src->et0_fao_evapotranspiration);
    _create_weather_str(&(*dest)->vapour_pressure_deficit, src->vapour_pressure_deficit);
    _create_weather_str(&(*dest)->wind_speed_10m, src->wind_speed_10m);
    _create_weather_str(&(*dest)->wind_speed_80m, src->wind_speed_80m);
    _create_weather_str(&(*dest)->wind_speed_120m, src->wind_speed_120m);
    _create_weather_str(&(*dest)->wind_speed_180m, src->wind_speed_180m);
    _create_weather_str(&(*dest)->wind_direction_10m, src->wind_direction_10m);
    _create_weather_str(&(*dest)->wind_direction_80m, src->wind_direction_80m);
    _create_weather_str(&(*dest)->wind_direction_120m, src->wind_direction_120m);
    _create_weather_str(&(*dest)->wind_direction_180m, src->wind_direction_180m);
    _create_weather_str(&(*dest)->wind_gusts_10m, src->wind_gusts_10m);
    _create_weather_str(&(*dest)->temperature_80m, src->temperature_80m);
    _create_weather_str(&(*dest)->temperature_120m, src->temperature_120m);
    _create_weather_str(&(*dest)->temperature_180m, src->temperature_180m);
    _create_weather_str(&(*dest)->soil_temperature_0cm, src->soil_temperature_0cm);
    _create_weather_str(&(*dest)->soil_temperature_6cm, src->soil_temperature_6cm);
    _create_weather_str(&(*dest)->soil_temperature_18cm, src->soil_temperature_18cm);
    _create_weather_str(&(*dest)->soil_temperature_54cm, src->soil_temperature_54cm);
    _create_weather_str(&(*dest)->soil_moisture_0_to_1cm, src->soil_moisture_0_to_1cm);
    _create_weather_str(&(*dest)->soil_moisture_3_to_9cm, src->soil_moisture_3_to_9cm);
    _create_weather_str(&(*dest)->soil_moisture_9_to_27cm, src->soil_moisture_9_to_27cm);
    _create_weather_str(&(*dest)->soil_moisture_27_to_81cm, src->soil_moisture_27_to_81cm);
}

void create_weather_hourly(weather_hourly **dest, weather_hourly *src)
{
    if (src == NULL)
        return;
        
    *dest = malloc(sizeof(weather_hourly_units));

    _create_weather_num(&(*dest)->time, src->time);
    _create_weather_num(&(*dest)->temperature_2m, src->temperature_2m);
    _create_weather_num(&(*dest)->relative_humidity_2m, src->relative_humidity_2m);
    _create_weather_num(&(*dest)->dew_point_2m, src->dew_point_2m);
    _create_weather_num(&(*dest)->apparent_temperature, src->apparent_temperature);
    _create_weather_num(&(*dest)->precipitation_probability, src->precipitation_probability);
    _create_weather_num(&(*dest)->precipitation, src->precipitation);
    _create_weather_num(&(*dest)->rain, src->rain);
    _create_weather_num(&(*dest)->showers, src->showers);
    _create_weather_num(&(*dest)->snowfall, src->snowfall);
    _create_weather_num(&(*dest)->snow_depth, src->snow_depth);
    _create_weather_num(&(*dest)->weather_code, src->weather_code);
    _create_weather_num(&(*dest)->pressure_msl, src->pressure_msl);
    _create_weather_num(&(*dest)->surface_pressure, src->surface_pressure);
    _create_weather_num(&(*dest)->cloud_cover, src->cloud_cover);
    _create_weather_num(&(*dest)->cloud_cover_low, src->cloud_cover_low);
    _create_weather_num(&(*dest)->cloud_cover_mid, src->cloud_cover_mid);
    _create_weather_num(&(*dest)->cloud_cover_high, src->cloud_cover_high);
    _create_weather_num(&(*dest)->visibility, src->visibility);
    _create_weather_num(&(*dest)->evapotranspiration, src->evapotranspiration);
    _create_weather_num(&(*dest)->et0_fao_evapotranspiration, src->et0_fao_evapotranspiration);
    _create_weather_num(&(*dest)->vapour_pressure_deficit, src->vapour_pressure_deficit);
    _create_weather_num(&(*dest)->wind_speed_10m, src->wind_speed_10m);
    _create_weather_num(&(*dest)->wind_speed_80m, src->wind_speed_80m);
    _create_weather_num(&(*dest)->wind_speed_120m, src->wind_speed_120m);
    _create_weather_num(&(*dest)->wind_speed_180m, src->wind_speed_180m);
    _create_weather_num(&(*dest)->wind_direction_10m, src->wind_direction_10m);
    _create_weather_num(&(*dest)->wind_direction_80m, src->wind_direction_80m);
    _create_weather_num(&(*dest)->wind_direction_120m, src->wind_direction_120m);
    _create_weather_num(&(*dest)->wind_direction_180m, src->wind_direction_180m);
    _create_weather_num(&(*dest)->wind_gusts_10m, src->wind_gusts_10m);
    _create_weather_num(&(*dest)->temperature_80m, src->temperature_80m);
    _create_weather_num(&(*dest)->temperature_120m, src->temperature_120m);
    _create_weather_num(&(*dest)->temperature_180m, src->temperature_180m);
    _create_weather_num(&(*dest)->soil_temperature_0cm, src->soil_temperature_0cm);
    _create_weather_num(&(*dest)->soil_temperature_6cm, src->soil_temperature_6cm);
    _create_weather_num(&(*dest)->soil_temperature_18cm, src->soil_temperature_18cm);
    _create_weather_num(&(*dest)->soil_temperature_54cm, src->soil_temperature_54cm);
    _create_weather_num(&(*dest)->soil_moisture_0_to_1cm, src->soil_moisture_0_to_1cm);
    _create_weather_num(&(*dest)->soil_moisture_3_to_9cm, src->soil_moisture_3_to_9cm);
    _create_weather_num(&(*dest)->soil_moisture_9_to_27cm, src->soil_moisture_9_to_27cm);
    _create_weather_num(&(*dest)->soil_moisture_27_to_81cm, src->soil_moisture_27_to_81cm);
}

void create_weather_daily_units(weather_daily_units **dest, weather_daily_units *src)
{
    if (src == NULL)
        return;
        
    *dest = malloc(sizeof(weather_daily_units));

    _create_weather_str(&(*dest)->time, src->time);
    _create_weather_str(&(*dest)->weather_code, src->weather_code);
    _create_weather_str(&(*dest)->temperature_2m_max, src->temperature_2m_max);
    _create_weather_str(&(*dest)->temperature_2m_min, src->temperature_2m_min);
    _create_weather_str(&(*dest)->apparent_temperature_max, src->apparent_temperature_max);
    _create_weather_str(&(*dest)->apparent_temperature_min, src->apparent_temperature_min);
    _create_weather_str(&(*dest)->sunrise, src->sunrise);
    _create_weather_str(&(*dest)->sunset, src->sunset);
    _create_weather_str(&(*dest)->daylight_duration, src->daylight_duration);
    _create_weather_str(&(*dest)->sunshine_duration, src->sunshine_duration);
    _create_weather_str(&(*dest)->uv_index_max, src->uv_index_max);
    _create_weather_str(&(*dest)->uv_index_clear_sky_max, src->uv_index_clear_sky_max);
    _create_weather_str(&(*dest)->precipitation_sum, src->precipitation_sum);
    _create_weather_str(&(*dest)->rain_sum, src->rain_sum);
    _create_weather_str(&(*dest)->showers_sum, src->showers_sum);
    _create_weather_str(&(*dest)->snowfall_sum, src->snowfall_sum);
    _create_weather_str(&(*dest)->precipitation_hours, src->precipitation_hours);
    _create_weather_str(&(*dest)->precipitation_probability_max, src->precipitation_probability_max);
    _create_weather_str(&(*dest)->wind_speed_10m_max, src->wind_speed_10m_max);
    _create_weather_str(&(*dest)->wind_gusts_10m_max, src->wind_gusts_10m_max);
    _create_weather_str(&(*dest)->wind_direction_10m_dominant, src->wind_direction_10m_dominant);
    _create_weather_str(&(*dest)->shortwave_radiation_sum, src->shortwave_radiation_sum);
    _create_weather_str(&(*dest)->et0_fao_evapotranspiration, src->et0_fao_evapotranspiration);
}

void create_weather_daily(weather_daily **dest, weather_daily *src)
{
    if (src == NULL)
        return;
        
    *dest = malloc(sizeof(weather_daily));

    _create_weather_num(&(*dest)->time, src->time);
    _create_weather_num(&(*dest)->weather_code, src->weather_code);
    _create_weather_num(&(*dest)->temperature_2m_max, src->temperature_2m_max);
    _create_weather_num(&(*dest)->temperature_2m_min, src->temperature_2m_min);
    _create_weather_num(&(*dest)->apparent_temperature_max, src->apparent_temperature_max);
    _create_weather_num(&(*dest)->apparent_temperature_min, src->apparent_temperature_min);
    _create_weather_num(&(*dest)->sunrise, src->sunrise);
    _create_weather_num(&(*dest)->sunset, src->sunset);
    _create_weather_num(&(*dest)->daylight_duration, src->daylight_duration);
    _create_weather_num(&(*dest)->sunshine_duration, src->sunshine_duration);
    _create_weather_num(&(*dest)->uv_index_max, src->uv_index_max);
    _create_weather_num(&(*dest)->uv_index_clear_sky_max, src->uv_index_clear_sky_max);
    _create_weather_num(&(*dest)->precipitation_sum, src->precipitation_sum);
    _create_weather_num(&(*dest)->rain_sum, src->rain_sum);
    _create_weather_num(&(*dest)->showers_sum, src->showers_sum);
    _create_weather_num(&(*dest)->snowfall_sum, src->snowfall_sum);
    _create_weather_num(&(*dest)->precipitation_hours, src->precipitation_hours);
    _create_weather_num(&(*dest)->precipitation_probability_max, src->precipitation_probability_max);
    _create_weather_num(&(*dest)->wind_speed_10m_max, src->wind_speed_10m_max);
    _create_weather_num(&(*dest)->wind_gusts_10m_max, src->wind_gusts_10m_max);
    _create_weather_num(&(*dest)->wind_direction_10m_dominant, src->wind_direction_10m_dominant);
    _create_weather_num(&(*dest)->shortwave_radiation_sum, src->shortwave_radiation_sum);
    _create_weather_num(&(*dest)->et0_fao_evapotranspiration, src->et0_fao_evapotranspiration);
}

/* load weather */

weather_data *load_file_weather(FILE *json_file, cJSON *json_root)
{
    char *json_raw = file_to_string(json_file);
    json_root = cJSON_ParseWithLength(json_raw, strlen(json_raw));
    free(json_raw);

    return load_json_weather_data(json_root);
}

weather_data *load_json_weather_data(cJSON *json_root)
{
    /* null check */

    if (json_root == NULL)
    {
        return NULL;
    }

    /* fill out weather_data struct */

    weather_data *data;
    data = malloc(sizeof(weather_data));

    /* zero out */

    data->latitude = NULL;
    data->longitude = NULL;
    data->elevation = NULL;
    data->timezone = NULL;
    data->timezone_abbreviation = NULL;
    data->current_units = NULL;
    data->current = NULL;
    data->hourly_units = NULL;
    data->hourly = NULL;
    data->daily_units = NULL;
    data->daily = NULL;

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

    /* data subsections */

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
    json_daily = cJSON_GetObjectItem(json_root, "daily");
    
    data->current_units = load_json_weather_current_units(json_current_units);
    data->current = load_json_weather_current(json_current);
    data->hourly_units = load_json_weather_hourly_units(json_hourly_units);
    data->hourly = load_json_weather_hourly(json_hourly);
    data->daily_units = load_json_weather_daily_units(json_daily_units);
    data->daily = load_json_weather_daily(json_daily);

    return data;
}

weather_current_units *load_json_weather_current_units(cJSON *json_root)
{
    /* null check */

    if (json_root == NULL)
    {
        return NULL;
    }

    /* fill out weather_current_units struct */

    weather_current_units *data;
    data = malloc(sizeof(weather_current_units));

    /* zero out */

    data->time = NULL;
    data->interval = NULL;
    data->temperature_2m = NULL;
    data->relative_humidity_2m = NULL;
    data->apparent_temperature = NULL;
    data->is_day = NULL;
    data->precipitation = NULL;
    data->rain = NULL;
    data->showers = NULL;
    data->snowfall = NULL;
    data->weather_code = NULL;
    data->cloud_cover = NULL;
    data->pressure_msl = NULL;
    data->surface_pressure = NULL;
    data->wind_speed_10m = NULL;
    data->wind_direction_10m = NULL;
    data->wind_gusts_10m = NULL;

    /* point to json data */

    cJSON *json_time;
    cJSON *json_interval;
    cJSON *json_temperature_2m;
    cJSON *json_relative_humidity;
    cJSON *json_apparent_temperature;
    cJSON *json_is_day;
    cJSON *json_precipitation;
    cJSON *json_rain;
    cJSON *json_showers;
    cJSON *json_snowfall;
    cJSON *json_weather_code;
    cJSON *json_cloud_cover;
    cJSON *json_pressure_msl;
    cJSON *json_surface_pressure;
    cJSON *json_wind_speed_10m;
    cJSON *json_wind_direction_10m;
    cJSON *json_wind_gusts_10m;
    
    json_time = cJSON_GetObjectItem(json_root, "time");
    json_interval = cJSON_GetObjectItem(json_root, "interval");
    json_temperature_2m = cJSON_GetObjectItem(json_root, "temperature_2m");
    json_relative_humidity = cJSON_GetObjectItem(json_root, "relative_humidity_2m");
    json_apparent_temperature = cJSON_GetObjectItem(json_root, "apparent_temperature");
    json_is_day = cJSON_GetObjectItem(json_root, "is_day");
    json_precipitation = cJSON_GetObjectItem(json_root, "precipitation");
    json_rain = cJSON_GetObjectItem(json_root, "rain");
    json_showers = cJSON_GetObjectItem(json_root, "showers");
    json_snowfall = cJSON_GetObjectItem(json_root, "snowfall");
    json_weather_code = cJSON_GetObjectItem(json_root, "weather_code");
    json_cloud_cover = cJSON_GetObjectItem(json_root, "cloud_cover");
    json_pressure_msl = cJSON_GetObjectItem(json_root, "pressure_msl");
    json_surface_pressure = cJSON_GetObjectItem(json_root, "surface_pressure");
    json_wind_speed_10m = cJSON_GetObjectItem(json_root, "wind_speed_10m");
    json_wind_direction_10m = cJSON_GetObjectItem(json_root, "wind_direction_10m");
    json_wind_gusts_10m = cJSON_GetObjectItem(json_root, "wind_gusts_10m");

    _set_weather_data_str(&data->time, json_time);
    _set_weather_data_str(&data->interval, json_interval);
    _set_weather_data_str(&data->temperature_2m, json_temperature_2m);
    _set_weather_data_str(&data->relative_humidity_2m, json_relative_humidity);
    _set_weather_data_str(&data->apparent_temperature, json_apparent_temperature);
    _set_weather_data_str(&data->is_day, json_is_day);
    _set_weather_data_str(&data->precipitation, json_precipitation);
    _set_weather_data_str(&data->rain, json_rain);
    _set_weather_data_str(&data->showers, json_showers);
    _set_weather_data_str(&data->snowfall, json_snowfall);
    _set_weather_data_str(&data->weather_code, json_weather_code);
    _set_weather_data_str(&data->cloud_cover, json_cloud_cover);
    _set_weather_data_str(&data->pressure_msl, json_pressure_msl);
    _set_weather_data_str(&data->surface_pressure, json_surface_pressure);
    _set_weather_data_str(&data->wind_speed_10m, json_wind_speed_10m);
    _set_weather_data_str(&data->wind_direction_10m, json_wind_direction_10m);
    _set_weather_data_str(&data->wind_gusts_10m, json_wind_gusts_10m);

    return data;
}

weather_current *load_json_weather_current(cJSON *json_root)
{
    /* null check */

    if (json_root == NULL)
    {
        return NULL;
    }

    /* fill out weather_current struct */

    weather_current *data;
    data = malloc(sizeof(weather_current));

    /* zero out */

    data->time = NULL;
    data->interval = NULL;
    data->temperature_2m = NULL;
    data->relative_humidity_2m = NULL;
    data->apparent_temperature = NULL;
    data->is_day = NULL;
    data->precipitation = NULL;
    data->rain = NULL;
    data->showers = NULL;
    data->snowfall = NULL;
    data->weather_code = NULL;
    data->cloud_cover = NULL;
    data->pressure_msl = NULL;
    data->surface_pressure = NULL;
    data->wind_speed_10m = NULL;
    data->wind_direction_10m = NULL;
    data->wind_gusts_10m = NULL;

    /* point to json data */

    cJSON *json_time;
    cJSON *json_interval;
    cJSON *json_temperature_2m;
    cJSON *json_relative_humidity;
    cJSON *json_apparent_temperature;
    cJSON *json_is_day;
    cJSON *json_precipitation;
    cJSON *json_rain;
    cJSON *json_showers;
    cJSON *json_snowfall;
    cJSON *json_weather_code;
    cJSON *json_cloud_cover;
    cJSON *json_pressure_msl;
    cJSON *json_surface_pressure;
    cJSON *json_wind_speed_10m;
    cJSON *json_wind_direction_10m;
    cJSON *json_wind_gusts_10m;
    
    json_time = cJSON_GetObjectItem(json_root, "time");
    json_interval = cJSON_GetObjectItem(json_root, "interval");
    json_temperature_2m = cJSON_GetObjectItem(json_root, "temperature_2m");
    json_relative_humidity = cJSON_GetObjectItem(json_root, "relative_humidity_2m");
    json_apparent_temperature = cJSON_GetObjectItem(json_root, "apparent_temperature");
    json_is_day = cJSON_GetObjectItem(json_root, "is_day");
    json_precipitation = cJSON_GetObjectItem(json_root, "precipitation");
    json_rain = cJSON_GetObjectItem(json_root, "rain");
    json_showers = cJSON_GetObjectItem(json_root, "showers");
    json_snowfall = cJSON_GetObjectItem(json_root, "snowfall");
    json_weather_code = cJSON_GetObjectItem(json_root, "weather_code");
    json_cloud_cover = cJSON_GetObjectItem(json_root, "cloud_cover");
    json_pressure_msl = cJSON_GetObjectItem(json_root, "pressure_msl");
    json_surface_pressure = cJSON_GetObjectItem(json_root, "surface_pressure");
    json_wind_speed_10m = cJSON_GetObjectItem(json_root, "wind_speed_10m");
    json_wind_direction_10m = cJSON_GetObjectItem(json_root, "wind_direction_10m");
    json_wind_gusts_10m = cJSON_GetObjectItem(json_root, "wind_gusts_10m");

    _set_weather_data_num(&data->time, json_time);
    _set_weather_data_num(&data->interval, json_interval);
    _set_weather_data_num(&data->temperature_2m, json_temperature_2m);
    _set_weather_data_num(&data->relative_humidity_2m, json_relative_humidity);
    _set_weather_data_num(&data->apparent_temperature, json_apparent_temperature);
    _set_weather_data_num(&data->is_day, json_is_day);
    _set_weather_data_num(&data->precipitation, json_precipitation);
    _set_weather_data_num(&data->rain, json_rain);
    _set_weather_data_num(&data->showers, json_showers);
    _set_weather_data_num(&data->snowfall, json_snowfall);
    _set_weather_data_num(&data->weather_code, json_weather_code);
    _set_weather_data_num(&data->cloud_cover, json_cloud_cover);
    _set_weather_data_num(&data->pressure_msl, json_pressure_msl);
    _set_weather_data_num(&data->surface_pressure, json_surface_pressure);
    _set_weather_data_num(&data->wind_speed_10m, json_wind_speed_10m);
    _set_weather_data_num(&data->wind_direction_10m, json_wind_direction_10m);
    _set_weather_data_num(&data->wind_gusts_10m, json_wind_gusts_10m);

    return data;
}

weather_hourly_units *load_json_weather_hourly_units(cJSON *json_root)
{
    /* null check */

    if (json_root == NULL)
    {
        return NULL;
    }

    /* fill out weather_hourly_units struct */

    weather_hourly_units *data;
    data = malloc(sizeof(weather_hourly_units));

    /* zero out */

    data->time = NULL;
    data->temperature_2m = NULL;
    data->relative_humidity_2m = NULL;
    data->dew_point_2m = NULL;
    data->apparent_temperature = NULL;
    data->precipitation_probability = NULL;
    data->precipitation = NULL;
    data->rain = NULL;
    data->showers = NULL;
    data->snowfall = NULL;
    data->snow_depth = NULL;
    data->weather_code = NULL;
    data->pressure_msl = NULL;
    data->surface_pressure = NULL;
    data->cloud_cover = NULL;
    data->cloud_cover_low = NULL;
    data->cloud_cover_mid = NULL;
    data->cloud_cover_high = NULL;
    data->visibility = NULL;
    data->evapotranspiration = NULL;
    data->et0_fao_evapotranspiration = NULL;
    data->vapour_pressure_deficit = NULL;
    data->wind_speed_10m = NULL;
    data->wind_speed_80m = NULL;
    data->wind_speed_120m = NULL;
    data->wind_speed_180m = NULL;
    data->wind_direction_10m = NULL;
    data->wind_direction_80m = NULL;
    data->wind_direction_120m = NULL;
    data->wind_direction_180m = NULL;
    data->wind_gusts_10m = NULL;
    data->temperature_80m = NULL;
    data->temperature_120m = NULL;
    data->temperature_180m = NULL;
    data->soil_temperature_0cm = NULL;
    data->soil_temperature_6cm = NULL;
    data->soil_temperature_18cm = NULL;
    data->soil_temperature_54cm = NULL;
    data->soil_moisture_0_to_1cm = NULL;
    data->soil_moisture_3_to_9cm = NULL;
    data->soil_moisture_9_to_27cm = NULL;
    data->soil_moisture_27_to_81cm = NULL;

    /* point to json data */

    cJSON *json_time;
    cJSON *json_temperature_2m;
    cJSON *json_relative_humidity_2m;
    cJSON *json_dew_point_2m;
    cJSON *json_apparent_temperature;
    cJSON *json_precipitation_probability;
    cJSON *json_precipitation;
    cJSON *json_rain;
    cJSON *json_showers;
    cJSON *json_snowfall;
    cJSON *json_snow_depth;
    cJSON *json_weather_code;
    cJSON *json_pressure_msl;
    cJSON *json_surface_pressure;
    cJSON *json_cloud_cover;
    cJSON *json_cloud_cover_low;
    cJSON *json_cloud_cover_mid;
    cJSON *json_cloud_cover_high;
    cJSON *json_visibility;
    cJSON *json_evapotranspiration;
    cJSON *json_et0_fao_evapotranspiration;
    cJSON *json_vapour_pressure_deficit;
    cJSON *json_wind_speed_10m;
    cJSON *json_wind_speed_80m;
    cJSON *json_wind_speed_120m;
    cJSON *json_wind_speed_180m;
    cJSON *json_wind_direction_10m;
    cJSON *json_wind_direction_80m;
    cJSON *json_wind_direction_120m;
    cJSON *json_wind_direction_180m;
    cJSON *json_wind_gusts_10m;
    cJSON *json_temperature_80m;
    cJSON *json_temperature_120m;
    cJSON *json_temperature_180m;
    cJSON *json_soil_temperature_0cm;
    cJSON *json_soil_temperature_6cm;
    cJSON *json_soil_temperature_18cm;
    cJSON *json_soil_temperature_54cm;
    cJSON *json_soil_moisture_0_to_1cm;
    cJSON *json_soil_moisture_3_to_9cm;
    cJSON *json_soil_moisture_9_to_27cm;
    cJSON *json_soil_moisture_27_to_81cm;

    json_time = cJSON_GetObjectItem(json_root, "time");
    json_temperature_2m = cJSON_GetObjectItem(json_root, "temperature_2m");
    json_relative_humidity_2m = cJSON_GetObjectItem(json_root, "relative_humidity_2m");
    json_dew_point_2m = cJSON_GetObjectItem(json_root, "dew_point_2m");
    json_apparent_temperature = cJSON_GetObjectItem(json_root, "apparent_temperature");
    json_precipitation_probability = cJSON_GetObjectItem(json_root, "precipitation_probability");
    json_precipitation = cJSON_GetObjectItem(json_root, "precipitation");
    json_rain = cJSON_GetObjectItem(json_root, "rain");
    json_showers = cJSON_GetObjectItem(json_root, "showers");
    json_snowfall = cJSON_GetObjectItem(json_root, "snowfall");
    json_snow_depth = cJSON_GetObjectItem(json_root, "snow_depth");
    json_weather_code = cJSON_GetObjectItem(json_root, "weather_code");
    json_pressure_msl = cJSON_GetObjectItem(json_root, "pressure_msl");
    json_surface_pressure = cJSON_GetObjectItem(json_root, "surface_pressure");
    json_cloud_cover = cJSON_GetObjectItem(json_root, "cloud_cover");
    json_cloud_cover_low = cJSON_GetObjectItem(json_root, "cloud_cover_low");
    json_cloud_cover_mid = cJSON_GetObjectItem(json_root, "cloud_cover_mid");
    json_cloud_cover_high = cJSON_GetObjectItem(json_root, "cloud_cover_high");
    json_visibility = cJSON_GetObjectItem(json_root, "visibility");
    json_evapotranspiration = cJSON_GetObjectItem(json_root, "evapotranspiration");
    json_et0_fao_evapotranspiration = cJSON_GetObjectItem(json_root, "et0_fao_evapotranspiration");
    json_vapour_pressure_deficit = cJSON_GetObjectItem(json_root, "vapour_pressure_deficit");
    json_wind_speed_10m = cJSON_GetObjectItem(json_root, "wind_speed_10m");
    json_wind_speed_80m = cJSON_GetObjectItem(json_root, "wind_speed_80m");
    json_wind_speed_120m = cJSON_GetObjectItem(json_root, "wind_speed_120m");
    json_wind_speed_180m = cJSON_GetObjectItem(json_root, "wind_speed_180m");
    json_wind_direction_10m = cJSON_GetObjectItem(json_root, "wind_direction_10m");
    json_wind_direction_80m = cJSON_GetObjectItem(json_root, "wind_direction_80m");
    json_wind_direction_120m = cJSON_GetObjectItem(json_root, "wind_direction_120m");
    json_wind_direction_180m = cJSON_GetObjectItem(json_root, "wind_direction_180m");
    json_wind_gusts_10m = cJSON_GetObjectItem(json_root, "wind_gusts_10m");
    json_temperature_80m = cJSON_GetObjectItem(json_root, "wind_gusts_80m");
    json_temperature_120m = cJSON_GetObjectItem(json_root, "wind_gusts_120m");
    json_temperature_180m = cJSON_GetObjectItem(json_root, "wind_gusts_180m");
    json_soil_temperature_0cm = cJSON_GetObjectItem(json_root, "soil_temperature_0cm");
    json_soil_temperature_6cm = cJSON_GetObjectItem(json_root, "soil_temperature_6cm");
    json_soil_temperature_18cm = cJSON_GetObjectItem(json_root, "soil_temperature_18cm");
    json_soil_temperature_54cm = cJSON_GetObjectItem(json_root, "soil_temperature_54cm");
    json_soil_moisture_0_to_1cm = cJSON_GetObjectItem(json_root, "moisture_0_to_1cm");
    json_soil_moisture_3_to_9cm = cJSON_GetObjectItem(json_root, "moisture_3_to_9cm");
    json_soil_moisture_9_to_27cm = cJSON_GetObjectItem(json_root, "moisture_9_to_27cm");
    json_soil_moisture_27_to_81cm = cJSON_GetObjectItem(json_root, "moisture_27_to_81cm");

    _set_weather_data_str(&data->time, json_time);
    _set_weather_data_str(&data->temperature_2m, json_temperature_2m);
    _set_weather_data_str(&data->relative_humidity_2m, json_relative_humidity_2m);
    _set_weather_data_str(&data->dew_point_2m, json_dew_point_2m);
    _set_weather_data_str(&data->apparent_temperature, json_apparent_temperature);
    _set_weather_data_str(&data->precipitation_probability, json_precipitation_probability);
    _set_weather_data_str(&data->precipitation, json_precipitation);
    _set_weather_data_str(&data->rain, json_rain);
    _set_weather_data_str(&data->showers, json_showers);
    _set_weather_data_str(&data->snowfall, json_snowfall);
    _set_weather_data_str(&data->snow_depth, json_snow_depth);
    _set_weather_data_str(&data->weather_code, json_weather_code);
    _set_weather_data_str(&data->pressure_msl, json_pressure_msl);
    _set_weather_data_str(&data->surface_pressure, json_surface_pressure);
    _set_weather_data_str(&data->cloud_cover, json_cloud_cover);
    _set_weather_data_str(&data->cloud_cover_low, json_cloud_cover_low);
    _set_weather_data_str(&data->cloud_cover_mid, json_cloud_cover_mid);
    _set_weather_data_str(&data->cloud_cover_high, json_cloud_cover_high);
    _set_weather_data_str(&data->visibility, json_visibility);
    _set_weather_data_str(&data->evapotranspiration, json_evapotranspiration);
    _set_weather_data_str(&data->et0_fao_evapotranspiration, json_et0_fao_evapotranspiration);
    _set_weather_data_str(&data->vapour_pressure_deficit, json_vapour_pressure_deficit);
    _set_weather_data_str(&data->wind_speed_10m, json_wind_speed_10m);
    _set_weather_data_str(&data->wind_speed_80m, json_wind_speed_80m);
    _set_weather_data_str(&data->wind_speed_120m, json_wind_speed_120m);
    _set_weather_data_str(&data->wind_speed_180m, json_wind_speed_180m);
    _set_weather_data_str(&data->wind_direction_10m, json_wind_direction_10m);
    _set_weather_data_str(&data->wind_direction_80m, json_wind_direction_80m);
    _set_weather_data_str(&data->wind_direction_120m, json_wind_direction_120m);
    _set_weather_data_str(&data->wind_direction_180m, json_wind_direction_180m);
    _set_weather_data_str(&data->wind_gusts_10m, json_wind_gusts_10m);
    _set_weather_data_str(&data->temperature_2m, json_temperature_80m);
    _set_weather_data_str(&data->temperature_120m, json_temperature_120m);
    _set_weather_data_str(&data->temperature_180m, json_temperature_180m);
    _set_weather_data_str(&data->soil_temperature_0cm, json_soil_temperature_0cm);
    _set_weather_data_str(&data->soil_temperature_6cm, json_soil_temperature_6cm);
    _set_weather_data_str(&data->soil_temperature_18cm, json_soil_temperature_18cm);
    _set_weather_data_str(&data->soil_temperature_54cm, json_soil_temperature_54cm);
    _set_weather_data_str(&data->soil_moisture_0_to_1cm, json_soil_moisture_0_to_1cm);
    _set_weather_data_str(&data->soil_moisture_3_to_9cm, json_soil_moisture_3_to_9cm);
    _set_weather_data_str(&data->soil_moisture_9_to_27cm, json_soil_moisture_9_to_27cm);
    _set_weather_data_str(&data->soil_moisture_9_to_27cm, json_soil_moisture_27_to_81cm);

    return data;
}

weather_hourly *load_json_weather_hourly(cJSON *json_root)
{
    /* null check */

    if (json_root == NULL)
    {
        return NULL;
    }

    /* fill out weather_hourly_units struct */

    weather_hourly *data;
    data = malloc(sizeof(weather_hourly));

    /* zero out */

    data->time = NULL;
    data->temperature_2m = NULL;
    data->relative_humidity_2m = NULL;
    data->dew_point_2m = NULL;
    data->apparent_temperature = NULL;
    data->precipitation_probability = NULL;
    data->precipitation = NULL;
    data->rain = NULL;
    data->showers = NULL;
    data->snowfall = NULL;
    data->snow_depth = NULL;
    data->weather_code = NULL;
    data->pressure_msl = NULL;
    data->surface_pressure = NULL;
    data->cloud_cover = NULL;
    data->cloud_cover_low = NULL;
    data->cloud_cover_mid = NULL;
    data->cloud_cover_high = NULL;
    data->visibility = NULL;
    data->evapotranspiration = NULL;
    data->et0_fao_evapotranspiration = NULL;
    data->vapour_pressure_deficit = NULL;
    data->wind_speed_10m = NULL;
    data->wind_speed_80m = NULL;
    data->wind_speed_120m = NULL;
    data->wind_speed_180m = NULL;
    data->wind_direction_10m = NULL;
    data->wind_direction_80m = NULL;
    data->wind_direction_120m = NULL;
    data->wind_direction_180m = NULL;
    data->wind_gusts_10m = NULL;
    data->temperature_80m = NULL;
    data->temperature_120m = NULL;
    data->temperature_180m = NULL;
    data->soil_temperature_0cm = NULL;
    data->soil_temperature_6cm = NULL;
    data->soil_temperature_18cm = NULL;
    data->soil_temperature_54cm = NULL;
    data->soil_moisture_0_to_1cm = NULL;
    data->soil_moisture_3_to_9cm = NULL;
    data->soil_moisture_9_to_27cm = NULL;
    data->soil_moisture_27_to_81cm = NULL;

    /* point to json data */

    cJSON *json_time;
    cJSON *json_temperature_2m;
    cJSON *json_relative_humidity_2m;
    cJSON *json_dew_point_2m;
    cJSON *json_apparent_temperature;
    cJSON *json_precipitation_probability;
    cJSON *json_precipitation;
    cJSON *json_rain;
    cJSON *json_showers;
    cJSON *json_snowfall;
    cJSON *json_snow_depth;
    cJSON *json_weather_code;
    cJSON *json_pressure_msl;
    cJSON *json_surface_pressure;
    cJSON *json_cloud_cover;
    cJSON *json_cloud_cover_low;
    cJSON *json_cloud_cover_mid;
    cJSON *json_cloud_cover_high;
    cJSON *json_visibility;
    cJSON *json_evapotranspiration;
    cJSON *json_et0_fao_evapotranspiration;
    cJSON *json_vapour_pressure_deficit;
    cJSON *json_wind_speed_10m;
    cJSON *json_wind_speed_80m;
    cJSON *json_wind_speed_120m;
    cJSON *json_wind_speed_180m;
    cJSON *json_wind_direction_10m;
    cJSON *json_wind_direction_80m;
    cJSON *json_wind_direction_120m;
    cJSON *json_wind_direction_180m;
    cJSON *json_wind_gusts_10m;
    cJSON *json_temperature_80m;
    cJSON *json_temperature_120m;
    cJSON *json_temperature_180m;
    cJSON *json_soil_temperature_0cm;
    cJSON *json_soil_temperature_6cm;
    cJSON *json_soil_temperature_18cm;
    cJSON *json_soil_temperature_54cm;
    cJSON *json_soil_moisture_0_to_1cm;
    cJSON *json_soil_moisture_3_to_9cm;
    cJSON *json_soil_moisture_9_to_27cm;
    cJSON *json_soil_moisture_27_to_81cm;

    json_time = cJSON_GetObjectItem(json_root, "time");
    json_temperature_2m = cJSON_GetObjectItem(json_root, "temperature_2m");
    json_relative_humidity_2m = cJSON_GetObjectItem(json_root, "relative_humidity_2m");
    json_dew_point_2m = cJSON_GetObjectItem(json_root, "dew_point_2m");
    json_apparent_temperature = cJSON_GetObjectItem(json_root, "apparent_temperature");
    json_precipitation_probability = cJSON_GetObjectItem(json_root, "precipitation_probability");
    json_precipitation = cJSON_GetObjectItem(json_root, "precipitation");
    json_rain = cJSON_GetObjectItem(json_root, "rain");
    json_showers = cJSON_GetObjectItem(json_root, "showers");
    json_snowfall = cJSON_GetObjectItem(json_root, "snowfall");
    json_snow_depth = cJSON_GetObjectItem(json_root, "snow_depth");
    json_weather_code = cJSON_GetObjectItem(json_root, "weather_code");
    json_pressure_msl = cJSON_GetObjectItem(json_root, "pressure_msl");
    json_surface_pressure = cJSON_GetObjectItem(json_root, "surface_pressure");
    json_cloud_cover = cJSON_GetObjectItem(json_root, "cloud_cover");
    json_cloud_cover_low = cJSON_GetObjectItem(json_root, "cloud_cover_low");
    json_cloud_cover_mid = cJSON_GetObjectItem(json_root, "cloud_cover_mid");
    json_cloud_cover_high = cJSON_GetObjectItem(json_root, "cloud_cover_high");
    json_visibility = cJSON_GetObjectItem(json_root, "visibility");
    json_evapotranspiration = cJSON_GetObjectItem(json_root, "evapotranspiration");
    json_et0_fao_evapotranspiration = cJSON_GetObjectItem(json_root, "et0_fao_evapotranspiration");
    json_vapour_pressure_deficit = cJSON_GetObjectItem(json_root, "vapour_pressure_deficit");
    json_wind_speed_10m = cJSON_GetObjectItem(json_root, "wind_speed_10m");
    json_wind_speed_80m = cJSON_GetObjectItem(json_root, "wind_speed_80m");
    json_wind_speed_120m = cJSON_GetObjectItem(json_root, "wind_speed_120m");
    json_wind_speed_180m = cJSON_GetObjectItem(json_root, "wind_speed_180m");
    json_wind_direction_10m = cJSON_GetObjectItem(json_root, "wind_direction_10m");
    json_wind_direction_80m = cJSON_GetObjectItem(json_root, "wind_direction_80m");
    json_wind_direction_120m = cJSON_GetObjectItem(json_root, "wind_direction_120m");
    json_wind_direction_180m = cJSON_GetObjectItem(json_root, "wind_direction_180m");
    json_wind_gusts_10m = cJSON_GetObjectItem(json_root, "wind_gusts_10m");
    json_temperature_80m = cJSON_GetObjectItem(json_root, "wind_gusts_80m");
    json_temperature_120m = cJSON_GetObjectItem(json_root, "wind_gusts_120m");
    json_temperature_180m = cJSON_GetObjectItem(json_root, "wind_gusts_180m");
    json_soil_temperature_0cm = cJSON_GetObjectItem(json_root, "soil_temperature_0cm");
    json_soil_temperature_6cm = cJSON_GetObjectItem(json_root, "soil_temperature_6cm");
    json_soil_temperature_18cm = cJSON_GetObjectItem(json_root, "soil_temperature_18cm");
    json_soil_temperature_54cm = cJSON_GetObjectItem(json_root, "soil_temperature_54cm");
    json_soil_moisture_0_to_1cm = cJSON_GetObjectItem(json_root, "moisture_0_to_1cm");
    json_soil_moisture_3_to_9cm = cJSON_GetObjectItem(json_root, "moisture_3_to_9cm");
    json_soil_moisture_9_to_27cm = cJSON_GetObjectItem(json_root, "moisture_9_to_27cm");
    json_soil_moisture_27_to_81cm = cJSON_GetObjectItem(json_root, "moisture_27_to_81cm");

    _set_weather_data_num(&data->time, json_time);
    _set_weather_data_num(&data->temperature_2m, json_temperature_2m);
    _set_weather_data_num(&data->relative_humidity_2m, json_relative_humidity_2m);
    _set_weather_data_num(&data->dew_point_2m, json_dew_point_2m);
    _set_weather_data_num(&data->apparent_temperature, json_apparent_temperature);
    _set_weather_data_num(&data->precipitation_probability, json_precipitation_probability);
    _set_weather_data_num(&data->precipitation, json_precipitation);
    _set_weather_data_num(&data->rain, json_rain);
    _set_weather_data_num(&data->showers, json_showers);
    _set_weather_data_num(&data->snowfall, json_snowfall);
    _set_weather_data_num(&data->snow_depth, json_snow_depth);
    _set_weather_data_num(&data->weather_code, json_weather_code);
    _set_weather_data_num(&data->pressure_msl, json_pressure_msl);
    _set_weather_data_num(&data->surface_pressure, json_surface_pressure);
    _set_weather_data_num(&data->cloud_cover, json_cloud_cover);
    _set_weather_data_num(&data->cloud_cover_low, json_cloud_cover_low);
    _set_weather_data_num(&data->cloud_cover_mid, json_cloud_cover_mid);
    _set_weather_data_num(&data->cloud_cover_high, json_cloud_cover_high);
    _set_weather_data_num(&data->visibility, json_visibility);
    _set_weather_data_num(&data->evapotranspiration, json_evapotranspiration);
    _set_weather_data_num(&data->et0_fao_evapotranspiration, json_et0_fao_evapotranspiration);
    _set_weather_data_num(&data->vapour_pressure_deficit, json_vapour_pressure_deficit);
    _set_weather_data_num(&data->wind_speed_10m, json_wind_speed_10m);
    _set_weather_data_num(&data->wind_speed_80m, json_wind_speed_80m);
    _set_weather_data_num(&data->wind_speed_120m, json_wind_speed_120m);
    _set_weather_data_num(&data->wind_speed_180m, json_wind_speed_180m);
    _set_weather_data_num(&data->wind_direction_10m, json_wind_direction_10m);
    _set_weather_data_num(&data->wind_direction_80m, json_wind_direction_80m);
    _set_weather_data_num(&data->wind_direction_120m, json_wind_direction_120m);
    _set_weather_data_num(&data->wind_direction_180m, json_wind_direction_180m);
    _set_weather_data_num(&data->wind_gusts_10m, json_wind_gusts_10m);
    _set_weather_data_num(&data->temperature_2m, json_temperature_80m);
    _set_weather_data_num(&data->temperature_120m, json_temperature_120m);
    _set_weather_data_num(&data->temperature_180m, json_temperature_180m);
    _set_weather_data_num(&data->soil_temperature_0cm, json_soil_temperature_0cm);
    _set_weather_data_num(&data->soil_temperature_6cm, json_soil_temperature_6cm);
    _set_weather_data_num(&data->soil_temperature_18cm, json_soil_temperature_18cm);
    _set_weather_data_num(&data->soil_temperature_54cm, json_soil_temperature_54cm);
    _set_weather_data_num(&data->soil_moisture_0_to_1cm, json_soil_moisture_0_to_1cm);
    _set_weather_data_num(&data->soil_moisture_3_to_9cm, json_soil_moisture_3_to_9cm);
    _set_weather_data_num(&data->soil_moisture_9_to_27cm, json_soil_moisture_9_to_27cm);
    _set_weather_data_num(&data->soil_moisture_9_to_27cm, json_soil_moisture_27_to_81cm);

    return data;
}

weather_daily_units *load_json_weather_daily_units(cJSON *json_root)
{
    /* null check */

    if (json_root == NULL)
    {
        return NULL;
    }

    /* fill out weather_daily_units struct */

    weather_daily_units *data;
    data = malloc(sizeof(weather_daily_units));

    /* zero out */

    data->time = NULL;
    data->weather_code = NULL;
    data->temperature_2m_max = NULL;
    data->temperature_2m_min = NULL;
    data->apparent_temperature_max = NULL;
    data->apparent_temperature_min = NULL;
    data->sunrise = NULL;
    data->sunset = NULL;
    data->daylight_duration = NULL;
    data->sunshine_duration = NULL;
    data->uv_index_max = NULL;
    data->uv_index_clear_sky_max = NULL;
    data->precipitation_sum = NULL;
    data->rain_sum = NULL;
    data->showers_sum = NULL;
    data->snowfall_sum = NULL;
    data->precipitation_hours = NULL;
    data->precipitation_probability_max = NULL;
    data->wind_speed_10m_max = NULL;
    data->wind_gusts_10m_max = NULL;
    data->wind_direction_10m_dominant = NULL;
    data->shortwave_radiation_sum = NULL;
    data->et0_fao_evapotranspiration = NULL;

    /* point to json data */

    cJSON *json_time;
    cJSON *json_weather_code;
    cJSON *json_temperature_2m_max;
    cJSON *json_temperature_2m_min;
    cJSON *json_apparent_temperature_max;
    cJSON *json_apparent_temperature_min;
    cJSON *json_sunrise;
    cJSON *json_sunset;
    cJSON *json_daylight_duration;
    cJSON *json_sunshine_duration;
    cJSON *json_uv_index_max;
    cJSON *json_uv_index_clear_sky_max;
    cJSON *json_precipitation_sum;
    cJSON *json_rain_sum;
    cJSON *json_showers_sum;
    cJSON *json_snowfall_sum;
    cJSON *json_precipitation_hours;
    cJSON *json_precipitation_probability_max;
    cJSON *json_wind_speed_10m_max;
    cJSON *json_wind_gusts_10m_max;
    cJSON *json_wind_direction_10m_dominant;
    cJSON *json_shortwave_radiation_sum;
    cJSON *json_et0_fao_evapotranspiration;

    json_time = cJSON_GetObjectItem(json_root, "time");
    json_weather_code = cJSON_GetObjectItem(json_root, "weather_code");
    json_temperature_2m_max = cJSON_GetObjectItem(json_root, "temperature_2m_max");
    json_temperature_2m_min = cJSON_GetObjectItem(json_root, "temperature_2m_min");
    json_apparent_temperature_max = cJSON_GetObjectItem(json_root, "apparent_temperature_max");
    json_apparent_temperature_min = cJSON_GetObjectItem(json_root, "apparent_temperature_min");
    json_sunrise = cJSON_GetObjectItem(json_root, "sunrise");
    json_sunset = cJSON_GetObjectItem(json_root, "sunset");
    json_daylight_duration = cJSON_GetObjectItem(json_root, "daylight_duration");
    json_sunshine_duration = cJSON_GetObjectItem(json_root, "sunshine_duration");
    json_uv_index_max = cJSON_GetObjectItem(json_root, "uv_index_max");
    json_uv_index_clear_sky_max = cJSON_GetObjectItem(json_root, "uv_index_clear_sky_max");
    json_precipitation_sum = cJSON_GetObjectItem(json_root, "precipitation_sum");
    json_rain_sum = cJSON_GetObjectItem(json_root, "rain_sum");
    json_showers_sum = cJSON_GetObjectItem(json_root, "showers_sum");
    json_snowfall_sum = cJSON_GetObjectItem(json_root, "snowfall_sum");
    json_precipitation_hours = cJSON_GetObjectItem(json_root, "precipitation_hours");
    json_precipitation_probability_max = cJSON_GetObjectItem(json_root, "precipitation_probability_max");
    json_wind_speed_10m_max = cJSON_GetObjectItem(json_root, "wind_speed_10m_max");
    json_wind_gusts_10m_max = cJSON_GetObjectItem(json_root, "wind_gusts_10m_max");
    json_wind_direction_10m_dominant = cJSON_GetObjectItem(json_root, "wind_direction_10m_dominant");
    json_shortwave_radiation_sum = cJSON_GetObjectItem(json_root, "shortwave_radiation_sum");
    json_et0_fao_evapotranspiration = cJSON_GetObjectItem(json_root, "et0_fao_evapotranspiration");

    _set_weather_data_str(&data->time, json_time);
    _set_weather_data_str(&data->weather_code, json_weather_code);
    _set_weather_data_str(&data->temperature_2m_max, json_temperature_2m_max);
    _set_weather_data_str(&data->temperature_2m_min, json_temperature_2m_min);
    _set_weather_data_str(&data->apparent_temperature_max, json_apparent_temperature_max);
    _set_weather_data_str(&data->apparent_temperature_min, json_apparent_temperature_min);
    _set_weather_data_str(&data->sunrise, json_sunrise);
    _set_weather_data_str(&data->sunset, json_sunset);
    _set_weather_data_str(&data->daylight_duration, json_daylight_duration);
    _set_weather_data_str(&data->sunshine_duration, json_sunshine_duration);
    _set_weather_data_str(&data->uv_index_max, json_uv_index_max);
    _set_weather_data_str(&data->uv_index_clear_sky_max, json_uv_index_clear_sky_max);
    _set_weather_data_str(&data->precipitation_sum, json_precipitation_sum);
    _set_weather_data_str(&data->rain_sum, json_rain_sum);
    _set_weather_data_str(&data->showers_sum, json_showers_sum);
    _set_weather_data_str(&data->snowfall_sum, json_snowfall_sum);
    _set_weather_data_str(&data->precipitation_hours, json_precipitation_hours);
    _set_weather_data_str(&data->precipitation_probability_max, json_precipitation_probability_max);
    _set_weather_data_str(&data->wind_speed_10m_max, json_wind_speed_10m_max);
    _set_weather_data_str(&data->wind_gusts_10m_max, json_wind_gusts_10m_max);
    _set_weather_data_str(&data->wind_direction_10m_dominant, json_wind_direction_10m_dominant);
    _set_weather_data_str(&data->shortwave_radiation_sum, json_shortwave_radiation_sum);
    _set_weather_data_str(&data->et0_fao_evapotranspiration, json_et0_fao_evapotranspiration);

    return data;
}

weather_daily *load_json_weather_daily(cJSON *json_root)
{
    /* null check */

    if (json_root == NULL)
    {
        return NULL;
    }

    /* fill out weather_daily struct */

    weather_daily *data;
    data = malloc(sizeof(weather_daily));

    /* zero out */

    data->time = NULL;
    data->weather_code = NULL;
    data->temperature_2m_max = NULL;
    data->temperature_2m_min = NULL;
    data->apparent_temperature_max = NULL;
    data->apparent_temperature_min = NULL;
    data->sunrise = NULL;
    data->sunset = NULL;
    data->daylight_duration = NULL;
    data->sunshine_duration = NULL;
    data->uv_index_max = NULL;
    data->uv_index_clear_sky_max = NULL;
    data->precipitation_sum = NULL;
    data->rain_sum = NULL;
    data->showers_sum = NULL;
    data->snowfall_sum = NULL;
    data->precipitation_hours = NULL;
    data->precipitation_probability_max = NULL;
    data->wind_speed_10m_max = NULL;
    data->wind_gusts_10m_max = NULL;
    data->wind_direction_10m_dominant = NULL;
    data->shortwave_radiation_sum = NULL;
    data->et0_fao_evapotranspiration = NULL;

    /* point to json data */

    cJSON *json_time;
    cJSON *json_weather_code;
    cJSON *json_temperature_2m_max;
    cJSON *json_temperature_2m_min;
    cJSON *json_apparent_temperature_max;
    cJSON *json_apparent_temperature_min;
    cJSON *json_sunrise;
    cJSON *json_sunset;
    cJSON *json_daylight_duration;
    cJSON *json_sunshine_duration;
    cJSON *json_uv_index_max;
    cJSON *json_uv_index_clear_sky_max;
    cJSON *json_precipitation_sum;
    cJSON *json_rain_sum;
    cJSON *json_showers_sum;
    cJSON *json_snowfall_sum;
    cJSON *json_precipitation_hours;
    cJSON *json_precipitation_probability_max;
    cJSON *json_wind_speed_10m_max;
    cJSON *json_wind_gusts_10m_max;
    cJSON *json_wind_direction_10m_dominant;
    cJSON *json_shortwave_radiation_sum;
    cJSON *json_et0_fao_evapotranspiration;

    json_time = cJSON_GetObjectItem(json_root, "time");
    json_weather_code = cJSON_GetObjectItem(json_root, "weather_code");
    json_temperature_2m_max = cJSON_GetObjectItem(json_root, "temperature_2m_max");
    json_temperature_2m_min = cJSON_GetObjectItem(json_root, "temperature_2m_min");
    json_apparent_temperature_max = cJSON_GetObjectItem(json_root, "apparent_temperature_max");
    json_apparent_temperature_min = cJSON_GetObjectItem(json_root, "apparent_temperature_min");
    json_sunrise = cJSON_GetObjectItem(json_root, "sunrise");
    json_sunset = cJSON_GetObjectItem(json_root, "sunset");
    json_daylight_duration = cJSON_GetObjectItem(json_root, "daylight_duration");
    json_sunshine_duration = cJSON_GetObjectItem(json_root, "sunshine_duration");
    json_uv_index_max = cJSON_GetObjectItem(json_root, "uv_index_max");
    json_uv_index_clear_sky_max = cJSON_GetObjectItem(json_root, "uv_index_clear_sky_max");
    json_precipitation_sum = cJSON_GetObjectItem(json_root, "precipitation_sum");
    json_rain_sum = cJSON_GetObjectItem(json_root, "rain_sum");
    json_showers_sum = cJSON_GetObjectItem(json_root, "showers_sum");
    json_snowfall_sum = cJSON_GetObjectItem(json_root, "snowfall_sum");
    json_precipitation_hours = cJSON_GetObjectItem(json_root, "precipitation_hours");
    json_precipitation_probability_max = cJSON_GetObjectItem(json_root, "precipitation_probability_max");
    json_wind_speed_10m_max = cJSON_GetObjectItem(json_root, "wind_speed_10m_max");
    json_wind_gusts_10m_max = cJSON_GetObjectItem(json_root, "wind_gusts_10m_max");
    json_wind_direction_10m_dominant = cJSON_GetObjectItem(json_root, "wind_direction_10m_dominant");
    json_shortwave_radiation_sum = cJSON_GetObjectItem(json_root, "shortwave_radiation_sum");
    json_et0_fao_evapotranspiration = cJSON_GetObjectItem(json_root, "et0_fao_evapotranspiration");

    _set_weather_data_num(&data->time, json_time);
    _set_weather_data_num(&data->weather_code, json_weather_code);
    _set_weather_data_num(&data->temperature_2m_max, json_temperature_2m_max);
    _set_weather_data_num(&data->temperature_2m_min, json_temperature_2m_min);
    _set_weather_data_num(&data->apparent_temperature_max, json_apparent_temperature_max);
    _set_weather_data_num(&data->apparent_temperature_min, json_apparent_temperature_min);
    _set_weather_data_num(&data->sunrise, json_sunrise);
    _set_weather_data_num(&data->sunset, json_sunset);
    _set_weather_data_num(&data->daylight_duration, json_daylight_duration);
    _set_weather_data_num(&data->sunshine_duration, json_sunshine_duration);
    _set_weather_data_num(&data->uv_index_max, json_uv_index_max);
    _set_weather_data_num(&data->uv_index_clear_sky_max, json_uv_index_clear_sky_max);
    _set_weather_data_num(&data->precipitation_sum, json_precipitation_sum);
    _set_weather_data_num(&data->rain_sum, json_rain_sum);
    _set_weather_data_num(&data->showers_sum, json_showers_sum);
    _set_weather_data_num(&data->snowfall_sum, json_snowfall_sum);
    _set_weather_data_num(&data->precipitation_hours, json_precipitation_hours);
    _set_weather_data_num(&data->precipitation_probability_max, json_precipitation_probability_max);
    _set_weather_data_num(&data->wind_speed_10m_max, json_wind_speed_10m_max);
    _set_weather_data_num(&data->wind_gusts_10m_max, json_wind_gusts_10m_max);
    _set_weather_data_num(&data->wind_direction_10m_dominant, json_wind_direction_10m_dominant);
    _set_weather_data_num(&data->shortwave_radiation_sum, json_shortwave_radiation_sum);
    _set_weather_data_num(&data->et0_fao_evapotranspiration, json_et0_fao_evapotranspiration);

    return data;
}

/* destroy weather stuff */

void destroy_weather_data(weather_data *data)
{
    free(data->latitude);
    free(data->longitude);
    free(data->elevation);
    free(data->timezone);
    free(data->timezone_abbreviation);

    destroy_weather_current_units(data->current_units);
    destroy_weather_current(data->current);
    destroy_weather_hourly_units(data->hourly_units);
    destroy_weather_hourly(data->hourly);
    destroy_weather_daily_units(data->daily_units);
    destroy_weather_daily(data->daily);

    free(data->current_units);
    free(data->current);
    free(data->hourly_units);
    free(data->hourly);
    free(data->daily_units);
    free(data->daily);
}

// TODO implement functions