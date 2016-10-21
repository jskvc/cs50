<?php

    // configuration
    require("../includes/config.php"); 
    
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if(empty($_POST["symbol"]) ||empty($_POST["shares"]))
        {
            apologize("Missing stock symbol or shares quantity.");
        }
         if(!preg_match("/^\d+$/", $_POST["buyshares"]) || $_POST["buyshares"] == 0)
        {
            apologize("Please enter a number of shares you want to purchase.");
        }  
        if(lookup($_POST["symbol"])===false)
        {
            apologize("Please enter a valid stock symbol.");
        }   
         
        $transaction = 'BUY';
                
        $stock = lookup($_POST["symbol"]);
       
        $cost = $stock["price"] * $_POST["shares"];   
        
         // add shares to holdings
         query("INSERT INTO holdings (id, symbol, shares) VALUES (?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + ?", 
                    $_SESSION["id"], strtoupper($_POST["symbol"]), $_POST["buyshares"], $_POST["buyshares"]);    
         query("UPDATE users SET cash = cash - ? WHERE id = ?", $cost, $_SESSION["id"]);
         query("INSERT INTO history (id, transaction, symbol, shares, price) VALUES (?, ?, ?, ?, ?)", $_SESSION["id"], $transaction, $_POST["symbol"], $_POST["shares"], $stock1["price"]);
         redirect("/"); 
    }
    else
    {
    // render portfolio
    render("portfolio.php", ["title" => "Portfolio"]);
    }
?>
