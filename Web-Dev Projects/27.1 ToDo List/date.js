//Default is used to export not perticular function
function getDate() {
    let options = {
        weekday: "long",
        month: "long",
        day: "numeric",
    };

    let today = new Date();
    let date = today.toLocaleDateString("en-US", options);

    return date;
}

//No 2 default in one js--
function getDay() {
    let options = {
        weekday: "long",
    };

    let today = new Date();
    let date = today.toLocaleDateString("en-US", options);

    return date;
}

export default {
    getDate,
    getDay,
};
