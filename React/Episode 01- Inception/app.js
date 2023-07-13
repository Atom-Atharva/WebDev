/**
 *
 * <div id="parent">
 *      <div id="child1">
 *          <h1>I am in H1 Tag!</h1>
 *          <h2>I am in H2 Tag!</h2>
 *      </div>
 *      <div id="child2">
 *          <h1>I am in H1 Tag!</h1>
 *          <h2>I am in H2 Tag!</h2>
 *      </div>
 * </div>
 *
 **/

// This react Element is an OBJECT--
const parent = React.createElement("div", { id: "parent" }, [
    React.createElement("div", { id: "child1" }, [
        React.createElement("h1", {}, "I am in H1 Tag!"),
        React.createElement("h2", {}, "I am in H2 Tag!"),
    ]),
    React.createElement("div", { id: "child2" }, [
        React.createElement("h1", {}, "I am in H1 Tag!"),
        React.createElement("h2", {}, "I am in H2 Tag!"),
    ]),
]);

const heading = React.createElement(
    "h1",
    // Props--
    { id: "heading", xyz: "abc" },
    "Hello World From React!"
);

const root = ReactDOM.createRoot(document.getElementById("root"));

console.log(heading); // Object
// root.render(heading);

console.log(parent); // Object

//* React Element(OBJECT) => HTML Element(Browser Understands)
root.render(parent);
