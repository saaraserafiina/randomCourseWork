// geolocation.js - handles user location for all pages

const API_KEY = "0f638f3b91e337b8242705232771445e";

export function setupLocateButton(btnId, errorId, onCityFound) {

    const btn = document.getElementById(btnId);
    if (!btn) return;

    btn.addEventListener("click", () => locateUser(btn, errorId, onCityFound));
}

function locateUser(btn, errorId, onCityFound) {

    if (!navigator.geolocation) {
        showLocationError(errorId, "Selaimesi ei tue paikannusta.");
        return;
    }

    btn.textContent = "⏳ Paikannetaan...";
    btn.disabled = true;

    navigator.geolocation.getCurrentPosition(

        async (position) => {
            const { latitude, longitude } = position.coords;
            const city = await getCityFromCoords(latitude, longitude, errorId);

            btn.textContent = "📍 Paikanna";
            btn.disabled = false;

            if (city) {
                localStorage.setItem("city", city);
                onCityFound(city);
            }
        },

        (error) => {
            btn.textContent = "📍 Paikanna";
            btn.disabled = false;

            switch (error.code) {
                case error.PERMISSION_DENIED:
                    showLocationError(errorId, "Sijaintilupa evätty.");
                    break;
                case error.POSITION_UNAVAILABLE:
                    showLocationError(errorId, "Sijaintia ei voitu määrittää.");
                    break;
                case error.TIMEOUT:
                    showLocationError(errorId, "Paikannus aikakatkaistiin.");
                    break;
                default:
                    showLocationError(errorId, "Paikannusvirhe. Yritä uudelleen.");
            }
        },

        { enableHighAccuracy: false, timeout: 10000, maximumAge: 0 }
    );
}

async function getCityFromCoords(lat, lon, errorId) {

    try {
        const response = await fetch(
            `https://api.openweathermap.org/geo/1.0/reverse?lat=${lat}&lon=${lon}&limit=1&appid=${API_KEY}`
        );
        if (!response.ok) throw new Error("Reverse geocoding failed");
        const data = await response.json();
        if (data.length === 0) throw new Error("No city found");
        return data[0].name;
    } catch (error) {
        console.error("Geolocation error:", error);
        showLocationError(errorId, "Kaupunkia ei löydy sijainnillasi.");
        return null;
    }
}

function showLocationError(errorId, message) {
    const el = document.getElementById(errorId);
    if (el) {
        el.textContent = message;
        setTimeout(() => { el.textContent = ""; }, 4000);
    }
}