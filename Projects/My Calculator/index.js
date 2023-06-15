let string = "";
let buttons = document.querySelectorAll(".button").length;

for (let i = 0; i < buttons; i++) {
    document
        .querySelectorAll(".button")
        [i].addEventListener("click", (button) => {
            let element = button.target.innerHTML;

            if (element == "C") {
                string = "";
            }
            if (element == "+/-") {
                string = string * -1;
            }

            if (element == "=") {
                string = eval(string);
            } else if (element != "C" && element != "M+" && element != "+/-") {
                console.log(button.target);
                string = string + element;
            }
            document.querySelector(".input-box").value = string;
        });
}
