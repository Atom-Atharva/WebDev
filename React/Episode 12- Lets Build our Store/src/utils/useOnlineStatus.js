import { useEffect, useState } from "react";

const useOnlineStatus = () => {
    // Check if ONLINE
    const [onlineStatus, setOnlineStatus] = useState(true);

    useEffect(() => {
        // Event Listener for Online Status.
        window.addEventListener("offline", () => {
            setOnlineStatus(false);
        });
        window.addEventListener("online", () => {
            setOnlineStatus(true);
        });
    }, []);

    // Boolean Value.
    return onlineStatus;
};

export default useOnlineStatus;
