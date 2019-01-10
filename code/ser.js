

var serialport=require('serialport');
var portName='COM15';//set the serialport NO.
const Readline = require('@serialport/parser-readline');//set the format
var sp=new serialport(portName,{
    baudRate:9600,
});
const parser=sp.pipe(new Readline({delimiter:'\r\n'}));

parser.on('data',function(data){
    var str=data.toString().split('#');
    console.log(data);//Dividing line
    sp.write("aaa");
})
