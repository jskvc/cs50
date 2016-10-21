<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["username"]))
        {
            apologize("You must provide a username.");
        }
        else if (empty($_POST["password"]))
        {
            apologize("You must provide a password.");
        }
        else if (empty($_POST["confirmation"]))
        {
            apologize("You must confirm your password.");
        }
        else if ($_POST["confirmation"] != $_POST["password"])
        {
            apologize("The password and it's confirmation doesn't match.");
        }
        
        // Register the user
            query("INSERT INTO users (username, hash, cash) VALUES(?, ?, 10000.00)", $_POST["username"], crypt($_POST["password"]));
            
            if ($query === false)
            {
                apologize("Could not register user.");
            }
            else
            {
                // Remember the session and redirect
                $rows = query("SELECT LAST_INSERT_ID() AS id");
                
                if (count($rows) == 1)
                {
                    $id = $rows[0]["id"];
                    
                    $_SESSION["id"] = $id;
                    
                    // remember username and current deposit
                    $_SESSION["username"] = $row["username"];
                    $_SESSION["cash"] = $row["cash"];
                    
                    redirect("/");
                }
                else
                {
                    $rows = query("SELECT LAST_INSERT_ID() AS id");
                     if (count($rows) == 1)
                    {
                        $id = $rows[0]["id"];
                        $_SESSION["id"] = $id;
                        // remember username and current deposit
                        $_SESSION["username"] = $row["username"];
                        $_SESSION["cash"] = $row["cash"];
                        
                        redirect("/");
                    }
                }
            }
    }
    

?>
