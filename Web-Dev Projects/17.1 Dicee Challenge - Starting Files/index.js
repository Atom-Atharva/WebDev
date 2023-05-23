//Image 1--
var randomNumber1 = Math.random();
randomNumber1 = Math.floor(randomNumber1 * 6 + 1);

document.querySelector(".img1").setAttribute("src","./images/dice"+randomNumber1+".png");

//Image 2--
var randomNumber2 = Math.random();
randomNumber2 = Math.floor(randomNumber2 * 6 + 1);

document.querySelector(".img2").setAttribute("src","./images/dice"+randomNumber2+".png");

//Display Winner--
var winner;
if(randomNumber1===randomNumber2){
    winner="Draw!";
}
else if(randomNumber1>randomNumber2){
    winner="🚩Player 1 Wins!"
}
else{
    winner="Player 2 Wins! 🚩"
}

document.querySelector("H1").innerHTML=winner;