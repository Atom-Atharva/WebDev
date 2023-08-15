# Episode 08

## Class Component (SEE UserClass.js)

-   As function component is a function, then class component is a class.

-   Class Component extends React.Component.

-   render() function - This function returns a piece of JSX.

-   Using Class Component is same as Functional Component.

-   Passing Props inside Class Component is received by constructor of the class.

-   Loading a class Based Component means we are creating an instance of that class.

### Super(props)

-   in constructor we need to call super() first and then we can use our props.

-   super() is used to call superclass method as well as access the superclass constructor. i.e, this is used to call the parent constructor. It is also called to use this keyword.

### State Variables

-   State Variables are new to React. So the old way to create useState Variable inside class Based Components are:

    -   We create state variables inside constructor by using this.state object.(SEE UserClass.js).

-   To update the state variable we should not modify our state variables directly.

-   To change state variable we use this.setState

## React Class Based Component Life Cycle

-   https://projects.wojtekmaj.pl/react-lifecycle-methods-diagram/

-   How component is mount up (loaded) onto the web-page.

-   When the UserClass.js is loaded inside the About.js, the instance of class is made and the constructor for the class is called.

-   Once constructor is called then render is called.

-   And after component is mounted into the page, componentDidMount() is called.

-   From Example in the code, Parent Constructor --> Parent Render --> Child Constructor --> Child Render --> Child ComponentDidMount --> Parent ComponentDidMount.

-   ComponentDidMount is used to make API Calls. This is same as using useEffect in Functional Component. As we need to first render our page and then wait for data from API this will enhance the User eXperience.

-   React optimizes the life Cycle of the component as it first render each component and then componentDidMount is called for each.

-   React Batch the render phase for multiple child.

-   For Example -- (SEE About.js and UserClass.js)

```
    - Parent Constructor
    - Parent Render

        - First Child Constructor
        - First Render

        - Second Child Constructor
        - Second Child Render

        <DOM UPDATED - IN SINGLE BATCH>

        - First ComponentDidMount
        - Second ComponentDidMount

    - Parent ComponentDidMount
```

-   See react life cycle diagram.
    https://projects.wojtekmaj.pl/react-lifecycle-methods-diagram/

-   Why this is happening (Batching Multiple Renders)?

    -   As onces the commit phase is start DOM update is done, see diagram.
    -   And DOM manipulation is most expensive thing in updating a component.

-   API calls in componentDidMount()

-   From the diagram of Life Cycle when the mounting is done updating is initiated.

-   React triggers the render once again, and then DOM is updated again.

-   After this componentDidUpdate() is called.

```
    --- MOUNTING ---

    - Constructor(Dummy)
    - Render (Dummy)
        <HTML Dummy>

    - ComponentDidMount
        <Api Call>
        <this.setState> --> State Variables is updated

    --- UPDATE ---

    - Render (API data)
        <HTML API data>

    - ComponentDidUpdate --> It will called after every render except starting one because componentDidMount will be called initially.
    - ComponentWillUnmount --> Called for disabling the UI, clearing space, stopping unwanted tasks, when we are leaving the page.

```

-   React Life Cycle is not for Functional Component.

-   setInterval after every second. (SEE UserClass.js)

-   Handling setInterval destruction in Functional Component (See User.js).
