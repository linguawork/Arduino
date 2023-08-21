#ifndef WEBPAGE_H
#define WEBPAGE_H

const char WEBPAGE_HTML[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
    <head>
        <title>The page for project 4</title>
    </head>
    <body>


        <h2>Press the button for </h2>
        <button onclick="sendRequest(1)">LED 1</button>
        <button onclick="sendRequest(2)">LED 2</button>
        <button onclick="sendRequest(3)">LED 3</button>
        <button onclick="sendRequest(4)">LED 4</button>
        <button onclick="sendRequest(5)">LED 5</button>
        <button onclick="sendRequest(6)">LED 6</button>
        <button onclick="sendRequest(7)">LED 7</button>
        <button onclick="sendRequest(8)">LED 8</button>
        <br>
        <button onclick="sendRequest(9)">LED 9</button>
        <button onclick="sendRequest(10)">LED 10</button>
        <button onclick="sendRequest(11)">LED 11</button>
        <button onclick="sendRequest(12)">LED 12</button>
        <button onclick="sendRequest(13)">LED 13</button>
        <button onclick="sendRequest(14)">LED 14</button>
        <button onclick="sendRequest(15)">LED 15</button>
        <button onclick="sendRequest(16)">LED 16</button>
        <br>
        <button onclick="sendRequest(17)">LED 17</button>
        <button onclick="sendRequest(18)">LED 18</button>
        <button onclick="sendRequest(19)">LED 19</button>
         <button onclick="sendRequest(20)">LED 20</button>
         <button onclick="sendRequest(21)">LED 21</button>
         <button onclick="sendRequest(22)">LED 22</button>
         <button onclick="sendRequest(23)">LED 23</button>
         <button onclick="sendRequest(24)">LED 24</button>
         <br>
         <button onclick="sendRequest(25)">LED 25</button>
         <button onclick="sendRequest(26)">LED 26</button>
         <button onclick="sendRequest(27)">LED 27</button>
         <button onclick="sendRequest(28)">LED 28</button>
         <button onclick="sendRequest(29)">LED 29</button>
         <button onclick="sendRequest(30)">LED 30</button>
         <button onclick="sendRequest(31)">LED 31</button>
         <button onclick="sendRequest(32)">LED 32</button>
         <br>
         <button onclick="sendRequest(33)">LED 33</button>
         <button onclick="sendRequest(34)">LED 34</button>
         <button onclick="sendRequest(35)">LED 35</button>
         <button onclick="sendRequest(36)">LED 36</button>
         <button onclick="sendRequest(37)">LED 37</button>
         <button onclick="sendRequest(38)">LED 38</button>
         <button onclick="sendRequest(39)">LED 39</button>
        <button onclick="sendRequest(40)">LED 40</button>
        <br>
        <button onclick="sendRequest(41)">LED 41</button>
        <button onclick="sendRequest(42)">LED 42</button>
        <button onclick="sendRequest(43)">LED 43</button>
        <button onclick="sendRequest(44)">LED 44</button>
        <button onclick="sendRequest(45)">LED 45</button>
        <button onclick="sendRequest(46)">LED 46</button>
        <button onclick="sendRequest(47)">LED 47</button>
        <button onclick="sendRequest(48)">LED 48</button>
        <br>
        <button onclick="sendRequest(49)">LED 49</button>
        <button onclick="sendRequest(50)">LED 50</button>
        <button onclick="sendRequest(51)">LED 51</button>
        <button onclick="sendRequest(52)">LED 52</button>
        <button onclick="sendRequest(53)">LED 53</button>
        <button onclick="sendRequest(54)">LED 54</button>
        <button onclick="sendRequest(55)">LED 55</button>
        <button onclick="sendRequest(56)">LED 56</button>
        <br>
        <button onclick="sendRequest(57)">LED 57</button>
        <button onclick="sendRequest(58)">LED 58</button>
        <button onclick="sendRequest(59)">LED 59</button>
        <button onclick="sendRequest(60)">LED 60</button>
        <button onclick="sendRequest(61)">LED 61</button>
        <button onclick="sendRequest(62)">LED 62</button>
        <button onclick="sendRequest(63)">LED 63</button>
        <button onclick="sendRequest(64)">LED 64</button>
        <br>
        <br>
        <br>

        <button onclick="sendPatternRequest(65)">Pattern</button>


        <script>
            function sendRequest(ledNumber) {
                const action = 'toggle'; // Use 'toggle' to switch between on and off
        
                fetch(`/led?led=${ledNumber}&action=${action}`)
                    .then(response => response.text())
                    .then(data => console.log(data))
                    .catch(error => console.error(error));
            }
        </script>
        

    </body>
</html>
)=====";

#endif
