#ifndef WEATHER_H
#define WEATHER_H

#include "cJSON/cJSON.h"

typedef struct _weather_data          weather_data;
typedef struct _weather_current_units weather_current_units;
typedef struct _weather_current       weather_current;
typedef struct _weather_hourly_units  weather_hourly_units;
typedef struct _weather_hourly        weather_hourly;
typedef struct _weather_daily_units   weather_daily_units;
typedef struct _weather_daily         weather_daily;

/* functions */

/* actually allocates and copies memory */

void create_weather_data(weather_data *dest, weather_data *src);

/* all this simply points to json bytes, doesn't copy anything! */

weather_data *load_file_weather(FILE *json_file);
weather_data *load_json_weather_data(cJSON *json_root);
weather_current_units *load_json_weather_current_units(cJSON *json_root);
weather_current *load_json_weather_current(cJSON *json_root);
weather_hourly_units *load_json_weather_hourly_units(cJSON *json_root);
weather_hourly *load_json_weather_hourly(cJSON *json_root);
weather_daily_units *load_json_weather_daily_units(cJSON *json_root);
weather_daily *load_json_weather_daily(cJSON *json_root);

void _set_weather_data_num(double **dest, cJSON *json_src);
void _set_weather_data_str(char **dest, cJSON *json_src);

/* 
 * weather information structs designed
 * around the 'open-meteo.com' api
 */

struct _weather_data
{
    double *latitude;
    double *longitude;
    double *elevation;
    char *timezone;
    char *timezone_abbreviation;
    struct _weather_current_units *current_units;
    struct _weather_current       *current;
    struct _weather_hourly_units  *hourly_units;
    struct _weather_hourly        *hourly;
    struct _weather_daily_units   *daily_units;
    struct _weather_daily         *daily;
};

struct _weather_current_units
{
    char *time;
    char *interval;
    char *temperature_2m;
    char *relative_humidity_2m;
    char *apparent_temperature;
    char *is_day;
    char *precipitation;
    char *rain;
    char *showers;
    char *snowfall;
    char *weather_code;
    char *cloud_cover;
    char *pressure_msl;
    char *surface_pressure;
    char *wind_speed_10m;
    char *wind_direction_10m;
    char *wind_gusts_10m;
};

struct _weather_current
{
    double *time;
    double *interval;
    double *temperature_2m;
    double *relative_humidity_2m;
    double *apparent_temperature;
    double *is_day;
    double *precipitation;
    double *rain;
    double *showers;
    double *snowfall;
    double *weather_code;
    double *cloud_cover;
    double *pressure_msl;
    double *surface_pressure;
    double *wind_speed_10m;
    double *wind_direction_10m;
    double *wind_gusts_10m;
};

struct _weather_hourly_units
{
    char *time;
    char *temperature_2m;
    char *relative_humidity_2m;
    char *dew_point_2m;
    char *apparent_temperature;
    char *precipitation_probability;
    char *precipitation;
    char *rain;
    char *showers;
    char *snowfall;
    char *snow_depth;
    char *weather_code;
    char *pressure_msl;
    char *surface_pressure;
    char *cloud_cover;
    char *cloud_cover_low;
    char *cloud_cover_mid;
    char *cloud_cover_high;
    char *visibility;
    char *evapotranspiration;
    char *et0_fao_evapotranspiration;
    char *vapour_pressure_deficit;
    char *wind_speed_10m;
    char *wind_speed_80m;
    char *wind_speed_120m;
    char *wind_speed_180m;
    char *wind_direction_10m;
    char *wind_direction_80m;
    char *wind_direction_120m;
    char *wind_direction_180m;
    char *wind_gusts_10m;
    char *temperature_80m;
    char *temperature_120m;
    char *temperature_180m;
    char *soil_temperature_0cm;
    char *soil_temperature_6cm;
    char *soil_temperature_18cm;
    char *soil_temperature_54cm;
    char *soil_moisture_0_to_1cm;
    char *soil_moisture_3_to_9cm;
    char *soil_moisture_9_to_27cm;
    char *soil_moisture_27_to_81cm;
};

struct _weather_hourly
{
    double *time;
    double *temperature_2m;
    double *relative_humidity_2m;
    double *dew_point_2m;
    double *apparent_temperature;
    double *precipitation_probability;
    double *precipitation;
    double *rain;
    double *showers;
    double *snowfall;
    double *snow_depth;
    double *weather_code;
    double *pressure_msl;
    double *surface_pressure;
    double *cloud_cover;
    double *cloud_cover_low;
    double *cloud_cover_mid;
    double *cloud_cover_high;
    double *visibility;
    double *evapotranspiration;
    double *et0_fao_evapotranspiration;
    double *vapour_pressure_deficit;
    double *wind_speed_10m;
    double *wind_speed_80m;
    double *wind_speed_120m;
    double *wind_speed_180m;
    double *wind_direction_10m;
    double *wind_direction_80m;
    double *wind_direction_120m;
    double *wind_direction_180m;
    double *wind_gusts_10m;
    double *temperature_80m;
    double *temperature_120m;
    double *temperature_180m;
    double *soil_temperature_0cm;
    double *soil_temperature_6cm;
    double *soil_temperature_18cm;
    double *soil_temperature_54cm;
    double *soil_moisture_0_to_1cm;
    double *soil_moisture_3_to_9cm;
    double *soil_moisture_9_to_27cm;
    double *soil_moisture_27_to_81cm;
};

struct _weather_daily_units
{
    char *time;
    char *weather_code;
    char *temperature_2m_max;
    char *temperature_2m_min;
    char *apparent_temperature_max;
    char *apparent_temperature_min;
    char *sunrise;
    char *sunset;
    char *daylight_duration;
    char *sunshine_duration;
    char *uv_index_max;
    char *uv_index_clear_sky_max;
    char *precipitation_sum;
    char *rain_sum;
    char *showers_sum;
    char *snowfall_sum;
    char *precipitation_hours;
    char *precipitation_probability_max;
    char *wind_speed_10m_max;
    char *wind_gusts_10m_max;
    char *wind_direction_10m_dominant;
    char *shortwave_radiation_sum;
    char *et0_fao_evapotranspiration;
};

struct _weather_daily
{
    double *time;
    double *weather_code;
    double *temperature_2m_max;
    double *temperature_2m_min;
    double *apparent_temperature_max;
    double *apparent_temperature_min;
    double *sunrise;
    double *sunset;
    double *daylight_duration;
    double *sunshine_duration;
    double *uv_index_max;
    double *uv_index_clear_sky_max;
    double *precipitation_sum;
    double *rain_sum;
    double *showers_sum;
    double *snowfall_sum;
    double *precipitation_hours;
    double *precipitation_probability_max;
    double *wind_speed_10m_max;
    double *wind_gusts_10m_max;
    double *wind_direction_10m_dominant;
    double *shortwave_radiation_sum;
    double *et0_fao_evapotranspiration;
};

#endif