/**
 * Line number 38 and 39 have been added and line number 61 has been edited, because:
 * Line 38: It makes sure that we do not lose the "current country" for which we are making a check,
 * as we will be resetting it on line number 49 which is there to prevent checking the same country again.
 *
 * Line 39: To make sure we do not check the resetted country (Basically, an empty character now).
 *
 * Line 61: I have assumed that the file is in the same directory and the name of it is input.txt
 * Although we can customize (make it more flexible/interactive) it further according to the needs of the user if needed.
 */

// Do not import anything that is not in the standard library
const fs = require('fs');

function read_scores(infile) {
    // Read `country: score` pairs from infile and return a list of pairs
    const filedata = fs.readFileSync(infile, 'utf8'); //Reads the txt file input
    const lines = filedata.replace(/\r\n/, "\n").split("\n"); //"lines" has contents of different lines
    let scores = [];
    for (let i in lines) {
        let line = lines[i].trim();
        if (!line)
            break;
        
        let [country, score] = line.split(":");
        scores.push([country.trim(), parseInt(score)]);
    }
    return scores; //scores will be like: [["India", 3], ["Australia", 31], ["India", 122], ...]
}

//The program attempts to count the number of countries against which this batsman has never scored a century.
function no_century_country_count(scores) {
    let no_century_count = 0;
    for(let i in scores) {
        let [country, score] = scores[i];
        
        // DEBUG: Preserve the current country and refrain from checking for the resetted countries
        let curr_country = country;
        if(curr_country == '') continue;
        
        let centuries = 0;
        for(let j=i; j<scores.length; j++) {
            let [country1, score1] = scores[j];
            if (curr_country == country1) {
                if (score1 >= 100)
                    centuries++;
                
                // disable checking of this same country again
                scores[j][0] = '';
            }
        }
        if (!centuries)
            // No century has been scored against `country`
            no_century_count++;
    }
    return no_century_count;
}

function run() {
    // read from stdin. 0 represents stdin for fs.readFile
    let scores = read_scores('input.txt');
    let no_century_count = no_century_country_count(scores);
    console.log(no_century_count);
}

run();  