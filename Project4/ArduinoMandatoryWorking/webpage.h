//upload this code of webpage with header in string value to header

#ifndef WEBPAGE_H
#define WEBPAGE_H

const char WEBPAGE_HTML[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
    <title>LED Matrix</title>
    <style>
        /* Style for the LED container */
        .led-matrix {
            display: grid;
            grid-template-columns: repeat(8, 40px); /* 8 columns */
            gap: 4px;
        }
        
        /* Style for individual LED items */
        .led-item {
            width: 40px;
            height: 40px;
            background-color: green;
            border: 2px solid #111;
            border-radius: 50%;
            display: flex;
            align-items: center;
            justify-content: center;
            font-size: 0.8em;
            color: white;
        }

        /* Style for the buttons and checkbox */
        .button-container {
            margin-top: 20px;
        }
    </style>
</head>
<body>

<h2>LED Matrix</h2>

<div class="led-matrix">
    <script>
        for (let i = 0; i < 64; i++) {
            document.write(`
                <div class="led-item">
                    <input type="checkbox" id="led${i}" name="leds" value="${i}">
                    <label for="led${i}">${i}</label>
                </div>
            `);
        }
    </script>
</div>

<div class="button-container">
    <button id="turnOnAll">Turn On All</button>
    <button id="turnOffAll">Turn Off All</button>
    <label for="displayPattern">Display Pattern</label>
    <input type="checkbox" id="displayPattern" name="displayPattern">
</div>

<script>
const leds = document.getElementsByName("leds");
const turnOnAllButton = document.getElementById("turnOnAll");
const turnOffAllButton = document.getElementById("turnOffAll");
const displayPatternCheckbox = document.getElementById("displayPattern");

function update_color(x, color) {
    const elements = document.getElementsByClassName(x);
    for (var i = 0; i < elements.length; i++) {
        elements[i].style.backgroundColor = color;
    }
}

function send_request(id, status) {
    fetch(`/led?id=${id}&status=${status}`)
        .then(response => response.json())
        .then(data => {
            console.log("Request sent successfully:", data);
        })
        .catch(error => {
            console.error("Error sending request:", error);
        });
}

function updateLeds(event) {
    const led = event.target;
    const id = led.value;
    const status = led.checked ? "true" : "false";

    send_request(id, status);
}

function turnOnAll() {
    leds.forEach(led => {
        led.checked = true;
    });
    update_color("led-item", "mediumpurple");
    send_request(-1, "on");
}

function turnOffAll() {
    leds.forEach(led => {
        led.checked = false;
    });
    update_color("led-item", "green");
    send_request(-1, "off");
}
function toggleDisplayPattern() {
    const isChecked = displayPatternCheckbox.checked;
    if (isChecked) {
        send_request(-1, "pattern");
        leds.forEach(led => {
            led.checked = false;
        });
        update_color("led-item", "green");
    } else {
        leds.forEach(led => {
          led.checked = false;
        });
        update_color("led-item", "green");
        send_request(-1, "not pattern");
    }
}

for (let i = 0; i < leds.length; i++) {
    leds[i].addEventListener("change", updateLeds);
}

turnOnAllButton.addEventListener("click", turnOnAll);
turnOffAllButton.addEventListener("click", turnOffAll);
displayPatternCheckbox.addEventListener("change", toggleDisplayPattern);
</script>


)=====";

#endif