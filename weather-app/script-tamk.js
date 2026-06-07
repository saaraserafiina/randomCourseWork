
window.addEventListener("DOMContentLoaded", () => {

    // event listener, kortit luodaan ja säädata haetaan kun sivu päivittyy

    getCurrentWeather();
});

async function getCurrentWeather() {

    // haetaan tämän hetkinen sää sekä viim. 24 h min ja max arvot

    const response = await fetch("https://webapi19sa-1.course.tamk.cloud/v1/weather/");
    const data = await response.json();



    const now = Date.now();
    const last24h = data.filter(item => now - new Date(item.date_time).getTime() < 24 * 60 * 60 * 1000);



    function getLatest(field) {

        // viimeisin tietokantaan tullut arvo

        const found = data.find(item => item.data[field] !== undefined);
        return found ? Number(found.data[field]).toFixed(2) : "--";
    }

    function getMin(field) {

        // pienin tietokantaan 24 h sisällä tullut arvo

        const vals = last24h.map(i => i.data[field]).filter(v => v != undefined);
        return vals.length ? Number(Math.min(...vals)).toFixed(2) : "--";

    }

    function getMax(field) {

        // suurin tietokantaan 24 h sisällä tullut arvo

        const vals = last24h.map(i => i.data[field]).filter(v => v != undefined);
        return vals.length ? Number(Math.max(...vals)).toFixed(2) : "--";
    }

    const latest = data[0];
    const timestamp = latest?.date_time
        ? new Date(latest.date_time).toLocaleTimeString("fi-FI", {hour: "2-digit", minute: "2-digit", second: "2-digit"})
        : "--";    



    const container = document.getElementById("current-tamk-container");
    container.innerHTML = `
        <div class="tamk-header">
        <span class="tamk-title">Tamkin sääaseman data</span>
        <span class="tamk-meta">ITC_2021 &nbsp; päivitetty: ${timestamp}</span>

        </div>
        <div class="tamk-cards">
        ${makeCard("Lämpötila", getLatest("temperature"), "°C", getMin("temperature"), getMax("temperature"))}
        ${makeCard("Sademäärä", getLatest("rain"), "mm", getMin("rain"), getMax("rain"))}
        ${makeCard("Tuulen suunta", getLatest("wind_direction"), "°", getMin("wind_direction"), getMax("wind_direction"))}
        ${makeCard("Valoisuus", getLatest("light"), "", getMin("light"), getMax("light"))}
 
        </div>

    `;

}

function makeCard(label, value, unit, min, max, type) {

    // korttien luonti

    return `
        <div class="tamk-card">
        <span class="tamk-card-label">${label}</span>
        <span class="tamk-card-value tamk-card-value--${type}">
            ${value ??  "-- "}${unit ? `<span class="tamk-card-unit">${unit}</span>` : ""}
        </span>
        <span class="tamk-card-minmax">Min ${min} · Max ${max}</span>

            </div>
    `;
}




