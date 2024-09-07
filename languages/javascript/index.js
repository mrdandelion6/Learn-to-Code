// function to make cookies

function setCookie(name, value, daysTillExpire) {
    const date = new Date();
    date.setTime(date.getTime() + daysTillExpire * 24 * 60 * 60 * 1000);
    // convert days to expire into ms (24)(60)(60)(1000)

    let expires = "expires=" + date.toUTCString();

    document.cookie = `${name}=${value}; ${expires}; path=/`;
}

setCookie("email", "bro@gmail.com", 5);
console.log(document.cookie);

// function for deleting cookies

function deleteCookie(name) {
    setCookie(name, null, null);
}

deleteCookie("lastName");

function getCookie(name) {
    const cDecoded = decodeURIComponent(document.cookie);

    const cArray = cDecoded.split("; ");

    // recall forEach loop vs for-of loop!
    // forEach loop cannot break out of loop and return a value,
    // hence we use a for-of loop. for-of loops are lie for (elem : array) loops in java or for x in array loops in python.
    for (elem of cArray) {
        nv = elem.split("=");

        if (nv[0] == name){ 
            return nv[1]; 
        }
    }

    return "no such cookie";
}

console.log(getCookie("email"));
console.log(getCookie("bars"));