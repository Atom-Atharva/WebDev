# Assignment 04

## JSX mandatory for React?

-   No it is not mandatory, it just make developer life easy to write code.
-   We can build a fully working app with out React.
-   JSX is just a syntax which is used to in-cooperate HTML like syntax inside JS.

## ES6 mandatory for React?

-   ES6 is standardization of JS for making code more readable and more accessible.
-   You can use the create-react-class module instead.

## Components Inside Components

-   `{TitleComponent} vs {<TitleComponent/>} vs {<TitleComponent></TitleComponent>}` all are same thing to insert other components inside component.

## Comments in JSX

-   To insert JS into JSX we need Curly brackets to tell compiler that the code inside is JS.
-   `{/* Comment Inside! */}`

## `<React.Fragment></React.Fragment> OR <></>`

-   As component only contains single parent thus we need to make `<div>` as parent which makes our code ugly, so to avoid this we can use this hidden parents which will not show in our code and can act as a single parent.

## Virtual DOM and Reconciliation

-   The virtual DOM (VDOM) is a programming concept where an ideal, or “virtual”, representation of a UI is kept in memory and synced with the “real” DOM by a library such as ReactDOM.
-   This process is called reconciliation.
-   Enable the declarative API of React: UI state is defined and DOM make sure it matches the state.
-   It is not same as Shadow DOM ( browser technology designed primarily for scoping variables and CSS in web components).

## React Fiber

-   This is New reconciliation engine in React 16.
-   Main goal is to enable incremental rendering (the ability to split rendering work into chunks and spread it out over multiple frames) of the virtual DOM.

## Keys in React

-   Key is important is rendering looping items, as it helps react to remember existing and new added item to render.
-   Without key all the elements will be re-rendered which takes time.
-   On Looping over an array requires unique ID which can work as KEY.

## Index as Keys.

-   We can use index as key but it is not preferred way to use index as key.
-   Index can change depending upon the position of the component, which can force the page to re-render all the items.

## Props in React

-   Props are the properties of a component.
-   Same as arguments in the function props act as arguments which makes our component dynamic.
-   Props is an object so we can use directly it as an object, or we can destructure this object to take out specific properties needed.

## Config Driven UI

-   When the page is dependent to data, i.e., UI will change according to data/config.
-   We have to make UI once and it will automatically update itself for the data.
