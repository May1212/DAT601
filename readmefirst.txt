1.open the terminal here, and run "npm install" to install dependency automaticly,of course,you should have installed nodejs.

2.after install all the dependencies, run "node startserver.js" to run the server.

3.open another terminal here, and run "npm install -g http-server" to install a httpserver.

4.run "httpserver",then open the browser to the url showed on the terminal.

5.modify the PORTNAME to your true arduino port.It's in the file "webaudio_visualizer.html" for about line 133.

6.click "webaudio_visualizer.html",the path is "code->webaudio_visualizer.html"

7.the led belt should light something.

hardware:
1.you should upload the arduinocode to arduino.
2.connect the led light to arduino.
    led belt    arduino
    5V-----------5V
    GND----------GND
    DIN----------A0
3.keep your usb cable connect to pc.