#ifndef WEATHER_H
#define WEATHER_H

#include <stdlib.h>

/* 
 * weather information structs designed
 * around the 'open-meteo.com' api
 */

// weather_data *get_weather_data();

typedef struct _weather_data          weather_data;
typedef struct _weather_current_units weather_current_units;
typedef struct _weather_current       weather_current;
typedef struct _weather_hourly_units  weather_hourly_units;
typedef struct _weather_hourly        weather_hourly;
typedef struct _weather_daily_units   weather_daily_units;
typedef struct _weather_daily         weather_daily;

struct _weather_data
{
    float latitude;
    float longitude;
    char *timezone;
    char *timezone_abbreviation;
    int elevation;
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
    char *relative_humidity;
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
    float time;
    float interval;
    float temperature_2m;
    float relative_humidity_2m;
    float apparent_temperature;
    float is_day;
    float precipitation;
    float rain;
    float showers;
    float snowfall;
    float weather_code;
    float cloud_cover;
    float pressure_msl;
    float surface_pressure;
    float wind_speed_10m;
    float wind_direction_10m;
    float wind_gusts_10m;
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
    float *time;
    float *temperature_2m;
    float *relative_humidity_2m;
    float *dew_point_2m;
    float *apparent_temperature;
    float *precipitation_probability;
    float *precipitation;
    float *rain;
    float *showers;
    float *snowfall;
    float *snow_depth;
    float *weather_code;
    float *pressure_msl;
    float *surface_pressure;
    float *cloud_cover;
    float *cloud_cover_low;
    float *cloud_cover_mid;
    float *cloud_cover_high;
    float *visibilty;
    float *evapotranspiration;
    float *et0_fao_evapotranspiration;
    float *vapour_pressure_deficit;
    float *wind_speed_10m;
    float *wind_speed_80m;
    float *wind_speed_120m;
    float *wind_speed_180m;
    float *wind_direction_10m;
    float *wind_direction_80m;
    float *wind_direction_120m;
    float *wind_direction_180m;
    float *wind_gusts_10m;
    float *temperature_80m;
    float *temperature_120m;
    float *temperature_180m;
    float *soil_temperature_0cm;
    float *soil_temperature_6cm;
    float *soil_temperature_18cm;
    float *soil_temperature_54cm;
    float *soil_moisture_0_to_1cm;
    float *soil_moisture_3_to_9cm;
    float *soil_moisture_9_to_27cm;
    float *soil_moisture_27_to_81cm;
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
    float *time;
    float *weather_code;
    float *temperature_2m_max;
    float *temperature_2m_min;
    float *apparent_temperature_max;
    float *apparent_temperature_min;
    float *sunrise;
    float *sunset;
    float *daylight_duration;
    float *sunshine_duration;
    float *uv_index_max;
    float *uv_index_clear_sky_max;
    float *precipitation_sum;
    float *rain_sum;
    float *showers_sum;
    float *snowfall_sum;
    float *precipitation_hours;
    float *precipitation_probability_max;
    float *wind_speed_10m_max;
    float *wind_gusts_10m_max;
    float *wind_direction_10m_dominant;
    float *shortwave_radiation_sum;
    float *et0_fao_evapotranspiration;
};

#endif