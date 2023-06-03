//.css method to change css of selector--
$("h1").css("color", "purple");
$("h1").css("font-size", "5rem");
$("h1").css("font-family", "cursive");

//$(selector)--> selects all the occurances
// $("button");

//Change the text--
// $("h1").text("Bye");

//Change html of tag--
// $("h1").html("<em>Hey</em>");

//Event Listner on jQuery--
// $("button").click(function () {
//     $("h1").css("color", "green");
// });

//Event Lisner on keypress--
$("body").keydown(function (event) {
    $("h1").text(event.key);
});
            