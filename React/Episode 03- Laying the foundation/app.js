import React from "react";
import ReactDOM from "react-dom/client";
import atomLogo from "./public/images/atom.png";

// React Element => Object (react.createElement() creates an object) => When we render this to DOM then it become HTML Element.
const heading = React.createElement(
    "h1",
    { id: "heading" },
    "Namaste React from Create Element"
);
console.log(heading);

// JSX (Make Our code Easy to write. It is not React)
// *JSX is not HTML in JS, It is a HTML-like or XML-like syntax.
// React Element
const jsxHeading = (
    <h1 id="heading" className="head">
        Namaste React using JSX!
    </h1>
);

console.log(jsxHeading);

const Header = () => {
    return (
        <div className="header">
            <img className="atom" src={atomLogo} alt="logo" />
            <form className="search-bar">
                <input type="text" placeholder="Search Bar"></input>
                <button type="submit">search</button>
            </form>
            <i className="fa-solid fa-user user-logo"></i>
        </div>
    );
};

// React Functional Components.
const Title = () => {
    return (
        <h1 className="head" tabIndex="5">
            This is a Title!
        </h1>
    );
};

// Normal JS Object--
const title = (
    <h1 className="head" tabIndex="5">
        This is a title!
    </h1>
);

// Variable.
const number = 10000;

// React Functional Component.
// Component Composition: We can use other functional Components in other components.
const HeadingComponent = () => {
    return (
        <div id="container">
            <Title></Title>
            <Title />
            {Title()}
            <h2>{number}</h2>
            <h2>{console.log(number)}</h2>
            {title}
            <h2 id="heading">Namaste React Functional Component!</h2>
        </div>
    );
};

// React.Fragment works as single parent of JSX expression.
// *React.Fragment --> Empty Tag
const Body = () => {
    return (
        <React.Fragment>
            <Header />
            <div className="container1">
                <Title></Title>
            </div>
            <div className="container2">
                <h2>I am Atharva!</h2>
            </div>
        </React.Fragment>
    );
};
// *Another Way of writing empty tag.
const Body2 = () => {
    return (
        <>
            <div className="container1"></div>
            <div className="container2"></div>
        </>
    );
};

const root = ReactDOM.createRoot(document.getElementById("root"));

// root.render(jsxHeading);
root.render(<Body />);
