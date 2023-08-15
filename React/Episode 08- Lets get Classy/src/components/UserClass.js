import React from "react";

// Class Component--
class UserClass extends React.Component {
    // To Receive Props--
    constructor(props) {
        // super is called because we need to use this keyword.
        super(props);

        // State Variables--
        this.state = {
            // state variables : default value
            // count: 0,
            // count2: 2,

            userInfo: {
                name: "Dummy",
                location: "Default",
                avatar_url: "http://dummyphoto",
            },
        };

        // console.log(props);
        console.log(this.props.name + "Constructor Called!");
    }

    // Called After the component is completely mounted into the page.
    async componentDidMount() {
        this.timer = setInterval(() => {
            console.log("Timer Started!");
        }, 1000);

        console.log(this.props.name + "ComponentDidMount Called!");

        // Same as useEffect()
        // It is used to make API calls.
        // Fetching Data from github API.
        const data = await fetch("https://api.github.com/users/atom-atharva");
        const json = await data.json();

        this.setState({
            userInfo: json,
        });

        console.log(json);
    }

    // Called After Updating UI. Each time new Render takes place except for starting one.
    componentDidUpdate() {
        console.log("ComponentDidUpdate Called!");
    }

    // Disabling from the UI. Called when we are leaving the page
    componentWillUnmount() {
        // This is used to clean your mess like timer, tasks, etc.
        // Reference of timer will be done by this. keyword.
        clearInterval(this.timer);

        console.log("ComponentWillUnmount Called!");
    }

    // Consist Render Function which will return a piece of JSX.
    render() {
        // Destructuring this.props
        // const { name, location } = this.props;
        // const { count, count2 } = this.state;

        console.log(name + "Render Called!");

        // debugger;
        return (
            <div className="user-card">
                {/* <h1>Count: {this.state.count}</h1> */}
                {/* <h1>Count: {count}</h1> */}
                {/* <h1>Count: {count2}</h1> */}

                {/* <button
                    onClick={() => {
                        //! NEVER UPDATE STATE VARIABLES DIRECTLY.
                        //! count = count + 1;

                        // Update State Variables.
                        this.setState({
                            count: count + 1,
                        });
                    }}
                >
                    Count++
                </button> */}

                <img
                    src={this.state.userInfo.avatar_url}
                    alt="DP"
                    height={100}
                ></img>

                {/* <h2>Name: {this.props.name}</h2> */}
                {/* <h2>Name: {name}</h2> */}
                <h2>Name: {this.state.userInfo.name}</h2>
                {/* <h3>Location: {this.props.location}</h3> */}
                <h3>Location: {this.state.userInfo.location}</h3>
                {/* <h3>Location: {location}</h3> */}
                <h4>Contact: @atomatharva</h4>
            </div>
        );
    }
}

export default UserClass;
