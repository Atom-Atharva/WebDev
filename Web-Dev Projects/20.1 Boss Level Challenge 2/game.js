//Check JS
// alert("HELLO");

//Check jQuery (in console)
// $("h1");

//Array to store colors--
var buttonColours = ["red", "blue", "green", "yellow"];

//Current Pattern--
var gamePattern = [];

//User Pattern--
var userClickedPattern = [];

//level of game--
var level = 0;

//Generate Sequence--
function nextSequence() {
    //Reset User Clicked Pattern--
    userClickedPattern = [];

    //Change Level--
    level++;
    $("#level-title").text("Level " + level);

    //Generate Random Number--
    var randomNumber = Math.floor(Math.random() * 4);

    //Choose a color from array--
    var randomChosenColour = buttonColours[randomNumber];

    //Push Color to Pattern--
    gamePattern.push(randomChosenColour);

    //Create a blink in chosen color--
    $("#" + randomChosenColour)
        .fadeOut(200)
        .fadeIn(200);

    //Play Sound of the button--
    playSound(randomChosenColour);
}

//Play Sound of the button pressed--
function playSound(key) {
    //Play a sound--
    var audio = new Audio("./sounds/" + key + ".mp3");
    audio.play();
}

//Event Listner on button click--
$(".btn").click(function () {
    var userChosenColour = $(this).attr("id");

    //Push color chosen into user pattern array--
    userClickedPattern.push(userChosenColour);

    //Play Sound on click--
    playSound(userChosenColour);

    //Animation--
    animatePress(userChosenColour);

    //Call Check Answer Function--
    if (userClickedPattern.length == gamePattern.length) {
        checkAnswer();
    }
});

//Animation to User Click--
function animatePress(currentColour) {
    $("#" + currentColour).addClass("pressed");
    setTimeout(function () {
        $("#" + currentColour).removeClass("pressed");
    }, 100);
}

//Start the game--
var toggle = 0;
$("body").keydown(function () {
    if (toggle === 0) {
        nextSequence();
        toggle = 1;
    }
});

//Check User Answer--
function checkAnswer() {
    if (userClickedPattern.toString() === gamePattern.toString()) {
        console.log("success");

        //Calling nextSequence--
        setTimeout(nextSequence, 1000);
    } else {
        console.log("wrong");

        //Play Wrong Sound--
        playSound("wrong");

        //Apply wrong css--
        $("body").addClass("game-over");
        setTimeout(function () {
            $("body").removeClass("game-over");
        }, 200);

        //Change Title to Game Over--
        $("#level-title").text("Game Over, Press Any Key to Restart");
        startOver();
    }
}

//Restart the Game--
function startOver() {
    gamePattern = [];
    level = 0;
    toggle = 0;
}
