// holy crap javascript is so much easier than C++
/* 
LINKED LIST EXPLANATION:
a list in which the previous element has the pointer to the next element's memory
this is slower than arrays to find a specific element.

however, while arrays have a finite size, linkedlists can theoretically be infinitely big.
*/
/* 
type "node linkedList.js" to run this program
*/

class Node {
    constructor(data) {
        this.next = undefined;
        this.data = data;
    }
}

class LinkedList {
    constructor() {
        this.head = undefined;
    }

    append(data) {
        if (!this.head) {
            this.head = new Node(data);
            return;
        }

        var current = this.head;

        while (current.next) {
            current = current.next;
        }

        current.next = new Node(data);
    }

    delete(data) {
        if (!this.head) return;

        if (this.head.data == data) {
            this.head = this.head.next;

            if (!this.head) return;
            this.delete(data);
        }

        var current = this.head;

        while (current.next) {
            if (current.next.data == data) {
                current.next = current.next.next;
            }

            current = current.next;
        }
    }

    print() {
        if (!this.head) return console.log("empty list");

        let current = this.head;
        console.log("\n")
        while (current) {
            console.log(current.data);
            current = current.next;
        }
    }
}

const main = () => {
    let list = new LinkedList();
    list.print();
    list.append(1);
    list.append(2);
    list.append(3);
    list.print();
    list.delete(2);
    list.print();

    return 0;
}

main();