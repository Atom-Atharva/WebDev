// Hook for useState variable--
import { useState, useEffect } from "react";

// Name as Parameter
const User = ({ name }) => {
    const [count, setCount] = useState(0);
    const [count2, setCount2] = useState(2);

    useEffect(() => {
        // API Calls--
        const timer = setInterval(() => {
            console.log("Timer Started!");
        }, 1000);

        // Same as ComponentWillUnmount()
        return () => {
            clearInterval(timer);
        };
    }, []);

    async function getUserInfo() {
        const data = await fetch("https://api.github.com/users/atom-atharva");
        const json = await data.json();

        console.log(json);
    }

    return (
        <div className="user-card">
            <h1>Count: {count}</h1>
            <h1>Count: {count2}</h1>
            <h2>Name: {name}</h2>
            <h3>Location: Indore</h3>
            <h4>Contact: @atomatharva</h4>
        </div>
    );
};

export default User;
