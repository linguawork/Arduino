#ifndef WEBPAGE_H
#define WEBPAGE_H

const char WEBPAGE_HTML[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
    <head>
        <title>The page for project 4</title>
    </head>
    <body>

        <!--
            Let's remake the buttons into switches,

            and create a pattern for Pattern button

        -->


        <h2>Press the button for </h2>
        <button id="button0" onclick="sendRequest(0)">LED 1</button>
        <button id="button1" onclick="sendRequest(1)">LED 2</button>
        <button id="button2" onclick="sendRequest(2)">LED 3</button>
        <button id="button3" onclick="sendRequest(3)">LED 4</button>
        <button id="button4" onclick="sendRequest(4)">LED 5</button>
        <button id="button5" onclick="sendRequest(5)">LED 6</button>
        <button id="button6" onclick="sendRequest(6)">LED 7</button>
        <button id="button7" onclick="sendRequest(7)">LED 8</button>
        <br>
        <button id="button8" onclick="sendRequest(8)">LED 9</button>
        <button id="button9" onclick="sendRequest(9)">LED 10</button>
        <button id="button10" onclick="sendRequest(10)">LED 11</button>
        <button id="button11" onclick="sendRequest(11)">LED 12</button>
        <button id="button12" onclick="sendRequest(12)">LED 13</button>
        <button id="button13" onclick="sendRequest(13)">LED 14</button>
        <button id="button14" onclick="sendRequest(14)">LED 15</button>
        <button id="button15" onclick="sendRequest(15)">LED 16</button>
        <br>
        <button id="button16" onclick="sendRequest(16)">LED 17</button>
        <button id="button17" onclick="sendRequest(17)">LED 18</button>
        <button id="button18" onclick="sendRequest(18)">LED 19</button>
        <button id="button19" onclick="sendRequest(19)">LED 20</button>
        <button id="button20" onclick="sendRequest(20)">LED 21</button>
        <button id="button21" onclick="sendRequest(21)">LED 22</button>
        <button id="button22" onclick="sendRequest(22)">LED 23</button>
        <button id="button23" onclick="sendRequest(23)">LED 24</button>
        <br>
        <button id="button24" onclick="sendRequest(24)">LED 25</button>
        <button id="button25" onclick="sendRequest(25)">LED 26</button>
        <button id="button26" onclick="sendRequest(26)">LED 27</button>
        <button id="button27" onclick="sendRequest(27)">LED 28</button>
        <button id="button28"onclick="sendRequest(28)">LED 29</button>
        <button id="button29" onclick="sendRequest(29)">LED 30</button>
        <button id="button30" onclick="sendRequest(30)">LED 31</button>
        <button id="button31" onclick="sendRequest(31)">LED 32</button>
        <br>
        <button id="button32" onclick="sendRequest(32)">LED 33</button>
        <button id="button33" onclick="sendRequest(33)">LED 34</button>
        <button id="button34" onclick="sendRequest(34)">LED 35</button>
        <button id="button35" onclick="sendRequest(35)">LED 36</button>
        <button id="button36" onclick="sendRequest(36)">LED 37</button>
        <button id="button37" onclick="sendRequest(37)">LED 38</button>
        <button id="button38" onclick="sendRequest(38)">LED 39</button>
        <button id="button39" onclick="sendRequest(39)">LED 40</button>
        <br>
        <button id="button40" onclick="sendRequest(40)">LED 41</button>
        <button id="button41" onclick="sendRequest(41)">LED 42</button>
        <button id="button42" onclick="sendRequest(42)">LED 43</button>
        <button id="button43" onclick="sendRequest(43)">LED 44</button>
        <button id="button44" onclick="sendRequest(44)">LED 45</button>
        <button id="button45" onclick="sendRequest(45)">LED 46</button>
        <button id="button46" onclick="sendRequest(46)">LED 47</button>
        <button id="button47" onclick="sendRequest(47)">LED 48</button>
        <br>
        <button id="button48" onclick="sendRequest(48)">LED 49</button>
        <button id="button49" onclick="sendRequest(49)">LED 50</button>
        <button id="button50" onclick="sendRequest(50)">LED 51</button>
        <button id="button51" onclick="sendRequest(51)">LED 52</button>
        <button id="button52" onclick="sendRequest(52)">LED 53</button>
        <button id="button53" onclick="sendRequest(53)">LED 54</button>
        <button id="button54" onclick="sendRequest(54)">LED 55</button>
        <button id="button55" onclick="sendRequest(55)">LED 56</button>
        <br>
        <button id="button56" onclick="sendRequest(56)">LED 57</button>
        <button id="button57" onclick="sendRequest(57)">LED 58</button>
        <button id="button58" onclick="sendRequest(58)">LED 59</button>
        <button id="button59" onclick="sendRequest(59)">LED 60</button>
        <button id="button60" onclick="sendRequest(60)">LED 61</button>
        <button id="button61" onclick="sendRequest(61)">LED 62</button>
        <button id="button62" onclick="sendRequest(62)">LED 63</button>
        <button id="button63" onclick="sendRequest(63)">LED 64</button>
        <br>
        <br>
        <br>

        <button id="button64" onclick="sendRequest(64)">Pattern</button>

        <style>
            .active {
                background-color: green; /* Change this to the desired color */
                color: #46a7f7;
            }
        </style>

        <script>
                function sendRequest(ledNumber = null) {
                    let url = "/led";
                    if (ledNumber !== null) {
                        url += `?led=${ledNumber}`;
                    }

                    fetch(url)
                        .then(response => response.text())
                        .then(data => {
                            console.log(data);
                            // Optional: Update the button appearance based on LED state
                            if (ledNumber !== null) {
                                const button = document.getElementById(`button${ledNumber}`);
                                button.classList.toggle("active", data.includes("turned on"));
                            } else {
                                const patternButton = document.getElementById(`button64`);
                                patternButton.classList.toggle("active", data.includes("activated"));
                            }
                        })
                        .catch(error => console.error(error));
                }

        </script>
        
        

    </body>
</html>
)=====";

#endif
