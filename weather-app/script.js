import { setupLocateButton } from "./geolocation.js";

const API_KEY = "0f638f3b91e337b8242705232771445e";

// DOM elements
const cityInput = document.getElementById("city-input");
const searchForm = document.getElementById("search-form");
const cityName = document.getElementById("city-name");
const temp = document.getElementById("temperature");
const feelsLike = document.getElementById("feels-like");
const humidity = document.getElementById("humidity");
const wind = document.getElementById("wind-speed");
const desc = document.getElementById("weather-description");
const updated = document.querySelector(".info");
const errorMsg = document.getElementById("location-error");

async function fetchWeather(city) {

    // Säädatan haku apilta kaupungin nimen perusteella

    try {
        const response = await fetch(
            `https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${API_KEY}&units=metric`
        );
        if (!response.ok) {
            throw new Error("Kaupunkia ei löydy tai virheellinen API-avain");
        }
        const data = await response.json();
        return data;
    } catch (error) {
        if (errorMsg) errorMsg.textContent = error.message;
    }
}

function updateUI(data) {

    // Käyttöliittymän päivitys

    cityName.textContent = data.name + ", " + data.sys.country;
    temp.textContent = Math.round(data.main.temp) + "°C";
    feelsLike.textContent = "Tuntuu kuin: " + Math.round(data.main.feels_like) + "°C";
    humidity.textContent = "Kosteus: " + data.main.humidity + "%";
    wind.textContent = "Tuuli: " + data.wind.speed + " m/s";
    desc.textContent = data.weather[0].description;
    updated.textContent = "Päivitetty: " + new Date().toLocaleTimeString();
    if (errorMsg) errorMsg.textContent = "";
}

async function getDataAndUpdateUI(city) {
    const currentWeather = await fetchWeather(city);
    if (currentWeather) updateUI(currentWeather);
}

searchForm.addEventListener("submit", (e) => {
    e.preventDefault();
    const city = cityInput.value.trim();
    if (city) {
        localStorage.setItem("city", city);
        getDataAndUpdateUI(city);
        cityInput.value = "";
    }
});

// use shared geolocation module - btn id, error id, callback
setupLocateButton("locate-btn", "location-error", getDataAndUpdateUI);

window.addEventListener("DOMContentLoaded", () => {
    const savedCity = localStorage.getItem("city");
    if (savedCity) {
        getDataAndUpdateUI(savedCity);
    }
});