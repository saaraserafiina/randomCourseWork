let tempChart;

const API_KEY = "0f638f3b91e337b8242705232771445e";

import { setupLocateButton } from "./geolocation";

const cityInput = document.getElementById("city-input");
const searchForm = document.getElementById("search-form");
const forecastCityName = document.getElementById("forecast-city-name");

searchForm.addEventListener("submit", (e) => {

    // suoritetaan kaikki toiminnot, kun painetaan submit-nappia

    e.preventDefault();
    const city = cityInput.value.trim();
    if (city) {
        localStorage.setItem("city", city);
        getDataAndUpdateUI(city);
        cityInput.value = "";
    }
});

const getForecastData = async (city) => {

    // haetaan ennusteen data apilta

    try {

        const response = await fetch(
            `https://api.openweathermap.org/data/2.5/forecast?q=${city}&appid=${API_KEY}&units=metric`,
        );

        if (!response.ok) {
            throw new Error("City not found");
        }

        const data = await response.json();
        return data;

    } catch (error) {
        console.error("Error fetching forecast data: ", error);
        alert("Could not fetch forecast data. Please try again.");
    }

};

function createCards(data) {

    // luodaan sääkortit

    const daily = {};

    data.list.forEach(item => {
        const date = new Date(item.dt * 1000);
        const dayKey = date.toISOString().split("T")[0];

        if (!daily[dayKey]) {
            daily[dayKey] = [];
        }
        daily[dayKey].push(item);
    });

    const container = document.getElementById("forecast-container");
    container.innerHTML = "";

    const weekdays = ["Su", "Ma", "Ti", "Ke", "To", "Pe", "La"];
    const today = new Date().toISOString().split("T")[0];

    Object.keys(daily)
        .filter(dayKey => dayKey > today)
        .slice(0, 5) // otetaan vain seuraavat 5 päivää
        .forEach(dayKey => {

        const dayData = daily[dayKey];
        const date = new Date(dayData[0].dt * 1000);
        const weekday = weekdays[date.getDay()];

        const tempMax = Math.round(Math.max(...dayData.map(d => d.main.temp_max)));
        const tempMin = Math.round(Math.min(...dayData.map(d => d.main.temp_min)));

        const card = document.createElement("div");
        card.className = "forecast-card";

        const iconCounts = {};
        dayData.forEach(item => {
            const id = item.weather[0].icon.replace("n", "d");
            iconCounts[id] = (iconCounts[id] || 0) + 1;
        });
        const icon = Object.keys(iconCounts).reduce((a, b) => iconCounts[a] > iconCounts[b] ? a : b);

        card.innerHTML = `
            <div class="day">${weekday}</div>
            <img 
                src="https://openweathermap.org/img/wn/${icon}@2x.png" 
                alt="${dayData[0].weather[0].description}"
                class="forecast-icon"
            >
            <div class="temp-max">${tempMax}°C</div>
            <div class="temp-min">${tempMin}°C</div>
        `;

        container.appendChild(card);
    });
}

function drawChart(data) {

    // kuvaajan piirto

    const ctx = document.getElementById("weather-chart");

    const labels = data.list.map(item => {
        const date = new Date(item.dt * 1000);
        const weekdays = ["Su", "Ma", "Ti", "Ke", "To", "Pe", "La"];

        return `${weekdays[date.getDay()]} ${date.getHours()}:00`;
    });

    const temps = data.list.map((item) => item.main.temp);

    if (tempChart) {
        tempChart.destroy();
    }

    tempChart = new Chart(ctx, {
        type: "line",
        data: {
            labels: labels,
            datasets: [
                {
                    label: "Lämpötila C",
                    data: temps,
                    borderColor: "orange",
                    backgroundColor: "rgba(255,165,0,0.2)",
                    tension: 0.3,
                },
            ],
        },
    });
}

export async function getDataAndUpdateUI(city) {

    // funktiokutsut

    const forecastData = await getForecastData(city);
    if (forecastData) {
        updateCityName(forecastData);
        drawChart(forecastData);
        createCards(forecastData);
    }
}

window.addEventListener("DOMContentLoaded", () => {
    const savedCity = localStorage.getItem("city");

    if (savedCity) {
        getDataAndUpdateUI(savedCity);
    }

    setupLocateButton(
        "locate-btn",
        "location-error",
        (city) => {
            getDataAndUpdateUI(city);
        }
    )
});

function updateCityName(data) {

    if (forecastCityName) {
        forecastCityName.textContent = `— ${data.city.name}, ${data.city.country}`;
    }
}