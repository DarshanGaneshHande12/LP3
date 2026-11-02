// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.0;

contract Bank {
    uint256 Balance = 0;
    address public accOwner;

    constructor() {
        accOwner = msg.sender;
    }

    // Deposit function
    function Deposit() public payable {
        require(accOwner == msg.sender, "You are not the account Owner");
        require(msg.value > 0, "depositing value should be greater than 0");
        Balance += msg.value;
    }

    // Withdraw function
    function Withdraw() public payable {
        require(accOwner == msg.sender, "You are not the account Owner");
        require(msg.value > 0, "withdrawal value should be greater than 0");
        Balance -= msg.value;
    }

    // Show balance function
    function showBalance() public view returns(uint256) {
        require(accOwner == msg.sender, "You are not the account Owner");
        return Balance;
    }
}

/*
COMMENTS / EXPLANATION:

1. SPDX-License-Identifier:
   Specifies the license of the smart contract.

2. pragma solidity ^0.8.0:
   Specifies the compatible Solidity compiler version.

3. contract Bank:
   Creates a smart contract named Bank.

4. uint256 Balance = 0:
   Stores the account balance, initially zero.

5. address public accOwner:
   Stores the owner's blockchain address.
   'public' automatically provides a getter function.

6. constructor():
   Executes only once when the contract is deployed.

7. accOwner = msg.sender:
   Makes the address deploying the contract the owner.
   msg.sender represents the caller's address.

8. function Deposit() public payable:
   Allows the function to receive Ether.
   'public' allows anyone to call the function.
   'payable' allows Ether to be sent with the call.

9. require(accOwner == msg.sender, ...):
   Checks whether the caller is the owner.
   If not, the transaction is reverted.

10. require(msg.value > 0, ...):
    Ensures that the amount sent is greater than zero.
    msg.value represents the Ether sent with the transaction,
    measured in wei.

11. Balance += msg.value:
    Adds the received Ether amount to the stored balance.

12. function Withdraw() public payable:
    Defines the withdrawal function.
    However, this implementation does not actually transfer
    Ether out of the contract.

13. Balance -= msg.value:
    Subtracts the Ether sent with the function call from
    the stored balance. This is not a proper withdrawal.

14. function showBalance() public view returns(uint256):
    Defines a function that returns the stored balance.

15. view:
    Indicates that the function reads state without modifying it.

16. return Balance:
    Returns the current stored balance.

IMPORTANT:
The Withdraw() function has a logical error. A proper
withdrawal function should accept an amount and transfer
Ether from the contract to the owner's address.
*/