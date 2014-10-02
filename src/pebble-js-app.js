var icon_clear_day           = 0;
var icon_clear_night         = 1;
var icon_cloudy              = 2;
var icon_fog                 = 3;
var icon_partly_cloudy_day   = 4;
var icon_partly_cloudy_night = 5;
var icon_light_rain          = 6;
var icon_heavy_rain          = 7;
var icon_thunder             = 8;
var icon_sleet               = 9;
var icon_snow                = 10;
var icon_wind                = 11;

function endsWith(str, suffix) {
  return str.indexOf(suffix, str.length - suffix.length) != -1;
}

function parseIcon(weather) {
  var weather_id = weather.id;
  var night = endsWith(weather.icon, "n");
  var icon = 'error';
  if (weather_id >= 200 && weather_id < 300) {
    icon = icon_thunder;
  } else if (weather_id >= 300 && weather_id < 400 || weather_id >= 520 && weather_id <= 600) {
    icon = icon_heavy_rain;
  } else if (weather_id >= 500 && weather_id < 511) {
    icon = icon_light_rain;
  } else if (weather_id == 511 || weather_id == 611 || weather_id == 612) {
    icon = icon_sleet;
  } else if (weather_id >= 600 && weather_id < 700) {
    icon = icon_snow;
  } else if (weather_id >= 700 && weather_id < 800) {
    icon = icon_fog;
  } else if (weather_id == 800) {
    if (night) {
      icon = icon_clear_night;
    } else {
      icon = icon_clear_day;
    }
  } else if (weather_id == 801 || weather_id == 802) {
    if (night) {
      icon = icon_partly_cloudy_night;
    } else {
      icon = icon_partly_cloudy_day;
    }
  } else if (weather_id >= 803 && weather_id < 900) {
    icon = icon_cloudy;
  } else if (weather_id >= 900) {
    icon = icon_wind;
  } else {
    icon = -1;
  }
  return icon;
}

var OPEN_WEATHER_URL = "http://api.openweathermap.org/data/2.5/weather";
function createWeatherRequestURL(lat, lon, lang) {
  return OPEN_WEATHER_URL + "?lat=" + lat + "&lon=" + lon + "&lang=" + lang + "&units=metric";
}

function fetchWeather(lat, lon, lang) {
//   console.log("featchWeather: lon=" + lon + ", lat=" + lat + ", lang=" + lang);
  var req = new XMLHttpRequest();
  req.open('GET', createWeatherRequestURL(lat, lon, lang), true);
  req.onload = function(e) {
    console.log("Request - onload: readyState=" + req.readyState + ", status=" + req.status + ", payload="  + req.responseText);
    console.log("e: " + e);
    if (req.readyState == 4 && req.status == 200) {
      if (req.status == 200) {
        var response = JSON.parse(req.responseText);
        
        var send = {};
//         if (response.currently) {
        var data = response;//.list[0];

        send.city = data.name;

        send.cur_temp = Number(data.main.temp).toFixed(0);
        send.min_temp = Number(data.main.temp_min).toFixed(0);
        send.max_temp = Number(data.main.temp_max).toFixed(0);

        var weather = response.weather[0];
        var icon = parseIcon(weather);
        send.icon = icon;
        send.description = weather.description;

//         console.log("Sending message: " + send);

        Pebble.sendAppMessage(send);
//         }
      } else { console.log("Error occurred loading weather: " + req); }
    } else {
      console.log("Error occurred loading weather data: "+ req);
    }
  };
  req.onerror = function(e) {
    console.log("Error occurred while requesting weather data: " + e);
  };
  req.onerror = function(e) {
    console.log("Timeout occurred while requesting weather data: " + e);
  };
  req.onabort = function(e) {
    console.log("Weather data request has been aborted: " + e);
  };
  req.send(null);
}

// function FtoC (f) {
//   return (f - 32) * 5 / 9;
// }

var locationAge = 60000 * 30; // 15 minutes
var locationOptions = { "timeout" : 30000, "maximumAge": locationAge, "enableHighAccuracy": false };

function locationSuccess(pos) {
//   console.log("locationSuccess: pos=" + pos);
  var coords = pos.coords;
  fetchWeather(coords.latitude, coords.longitude, 'pl');
}

function locationError(err) {
  console.warn('location error (' + err.code + '): ' + err.message);
  Pebble.sendAppMessage({
    "success":"false"
  });
}

Pebble.addEventListener("ready",
                       function(e) {
                         console.log("Ready - connect! " + e.ready);
//                          navigator.geolocation.getCurrentPosition(locationSuccess, locationError, locationOptions);
//                          navigator.geolocation.watchPosition(locationSuccess, locationError, locationOptions);
                         console.log(e.type);
                       });

Pebble.addEventListener("appmessage",
                       function(e) {
                         console.log("appmessage: "+ e.type);
                         navigator.geolocation.getCurrentPosition(locationSuccess, locationError, locationOptions);
//                          console.log("message!");
                       });

