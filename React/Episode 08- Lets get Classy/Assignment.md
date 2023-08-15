# Assignment 08

## Nested Routes

-   https://www.geeksforgeeks.org/implement-nested-routes-in-react-js-react-router-dom-v6/

-   One of the features of React Router DOM V6 is that it now comes with a <Routes> element. This is an upgrade as it comes with features like relative routing and linking, automatic route ranking, and nested routes and layouts. In our app, we will have two routes, one for the Home page and another for the Courses page. Under the Courses page, we will have again two routes, one for the Search component and the other for the List component. Thus we need to implement nested routing in the Courses page in order to render the selected component.

```
function App() {
    return (
        <div className="App">
            <Router>
                <nav>
                    <Link to="/">Home</Link>
                    <Link to="courses">Courses</Link>
                </nav>
                <Routes>
                    <Route path="/" element={<Home />} />
                    <Route path="/courses" element={<Courses />}>
                        <Route path="search" element={<Search />} />
                        <Route path="list" element={<List />} />
                    </Route>
                </Routes>
            </Router>
        </div>
    );
}
```

## createHashRouter

-   Same as createBrowserRouter

-   Useful if you are unable to configure your web server to direct all traffic to your React Router application.

-   Instead of using normal URLs, it will use the hash (#) portion of the URL to manage the "application URL".

-   Using Hash URL is not recommended.

## createMemoryRouter

-   Instead of using the browser's history, a memory router manages its own history stack in memory.

-   It's primarily useful for testing and component development tools like Storybook, but can also be used for running React Router in any non-browser environment.

## Order of Life Cycle Method of Class Component

-   It consist of 3 Phases--
    1. Mounting
    2. Updating
    3. Unmounting

## ComponentDidMount

-   It is used to mount the component inside the page on Initial Render.

## ComponentWillUnmount

-   It is used to free up the space or clear tasks which are unnecessary for the app.

-   Example- See UserClass.js.

## Why we use super(props) in constructor

-   super() function calls the constructor of parent class on which the existing class is extending.

-   This allow us to use this keyword and also help us to use the variable of the parent class.

## Why can't we have the callback function of useEffect async?

-   This is because the useEffect hook expects its effect function to return either a cleanup function or nothing at all.

-   This is due to the useEffect() hook's callback function's asynchronous execution and lack of blocking. Therefore, we must follow a specific pattern if we want to call an asynchronous function inside the useEffect() hook.

-   The special pattern is to create a new function that is declared inside the useEffect() hook and that contains the async function, and then we can call this new function inside the useEffect() hook. Here's an example:

```
import React, { useEffect } from 'react';

function App() {
  useEffect(() => {
    async function fetchData() {
      const response = await fetch('https://example.com/data');
      const data = await response.json();
      console.log(data);
    }

    fetchData();
  }, []);

  return <div>Hello World</div>;
}
```

-   As a result, since useEffect() is an asynchronous, non-blocking function, async callbacks cannot be made directly inside of it. To make sure the asynchronous code executes as intended, we can use a different way that declares a new function inside the "useEffect()" hook.
