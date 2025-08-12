const { SerialPort, ReadlineParser } = require('serialport');
const robotJs = require('robotjs');
const port = new SerialPort({ path: 'COM4', baudRate: 9600 });
const parser = port.pipe(new ReadlineParser({ delimiter: '\n' }));
let prevDirn = [];
parser.on('data', (line) => {
  try {
    const obj = JSON.parse(line);
    console.log(obj);
    if(obj.dirn!='n') {
        if(obj.dirn == 'w') {
            prevDirn.push('w');
            robotJs.keyToggle('w', 'down');
        }
        else if(obj.dirn == 's') {
            prevDirn.push('s');
            robotJs.keyToggle('s', 'down');
        }
        else if(obj.dirn == 'q') {
            prevDirn.push('w');
            prevDirn.push('d');
            robotJs.keyToggle('w', 'down');
            robotJs.keyToggle('d', 'down');
        }
        else if(obj.dirn == 'e') {
            prevDirn.push('w');
            prevDirn.push('a');
            robotJs.keyToggle('w', 'down');
            robotJs.keyToggle('a', 'down');
        }
        else if(obj.dirn == 'r') {
            prevDirn.push('s');
            prevDirn.push('a');
            robotJs.keyToggle('s', 'down');
            robotJs.keyToggle('a', 'down');
        }
        else if(obj.dirn == 't') {
            prevDirn.push('s');
            prevDirn.push('d');
            robotJs.keyToggle('s', 'down');
            robotJs.keyToggle('d', 'down');
        }
    }
    else {
        prevDirn.forEach((e) => {
            robotJs.keyToggle(e, 'up');
        });
        prevDirn = [];
    }
    if(obj.boost == 1) {
        robotJs.mouseToggle('down', 'left');
    }
    else robotJs.mouseToggle('up', 'left');
    if(obj.right == 1) {
        robotJs.mouseClick('right');
    }
    if(obj.shift == 1) {
        robotJs.keyToggle('shift', 'down');
    }
    else robotJs.keyToggle('shift', 'up');
  } catch (err) {
    // console.error('Invalid JSON:', line);
    console.log(err)
  }
});
wwwwwWWWW
