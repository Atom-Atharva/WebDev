import { useDispatch, useSelector } from "react-redux";
import ItemList from "./ItemList";
import { clearCart } from "../utils/cartSlice";

const Cart = () => {
    // BAD PRACTICE (Very less efficient)--
    // This will update on changing whole store rather than just cart slice.
    // const store = useSelector((store) => store);
    // const cartItems = store.cart.items;

    // GOOD PRACTICE--
    const cartItems = useSelector((store) => store.cart.items);

    const dispatch = useDispatch();

    const handleClearCart = () => {
        dispatch(clearCart());
    };

    return (
        <div className="text-center p-4 m-4">
            <h1 className="text-2xl font-bold">Cart</h1>
            <div className="w-7/12 m-auto">
                {cartItems.length === 0 ? (
                    <h1 className="text-xl m-4">
                        Cart is Empty! Add Items to the cart.
                    </h1>
                ) : (
                    <ItemList items={cartItems} />
                )}

                <button
                    className="p-2 m-2 bg-black text-white rounded-lg"
                    onClick={handleClearCart}
                >
                    Clear Cart
                </button>
            </div>
        </div>
    );
};

export default Cart;
