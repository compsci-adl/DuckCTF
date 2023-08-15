<!DOCTYPE html>
<html lang="en">
<head>
  <!-- Basic Page Needs
  –––––––––––––––––––––––––––––––––––––––––––––––––– -->
  <meta charset="utf-8">
  <title>The Unofficial Bean Codex - Home</title>
  <meta name="description" content="">
  <meta name="author" content="">

  <!-- Mobile Specific Metas
  –––––––––––––––––––––––––––––––––––––––––––––––––– -->
  <meta name="viewport" content="width=device-width, initial-scale=1">

  <!-- FONT
  –––––––––––––––––––––––––––––––––––––––––––––––––– -->
  <link href="//fonts.googleapis.com/css?family=Arvo:400,300,700" rel="stylesheet" type="text/css">
  <link href="//fonts.googleapis.com/css?family=Borel:400,300,600" rel="stylesheet" type="text/css">

  <!-- CSS
  –––––––––––––––––––––––––––––––––––––––––––––––––– -->
  <link rel="stylesheet" href="css/normalize.css">
  <link rel="stylesheet" href="css/skeleton.css">
  <link rel="stylesheet" href="css/main.css">

  <!-- Favicon
  –––––––––––––––––––––––––––––––––––––––––––––––––– -->
  <link rel="icon" type="image/png" href="images/favicon.png">

</head>
<body>

  <!-- Primary Page Layout
  –––––––––––––––––––––––––––––––––––––––––––––––––– -->
  <div class="container" style="margin-top: 5%; margin-bottom: 5%">
    <div class="row">
        <h4 id="title">🫘 Bean Codex</h4>
        <p>An unoffical, community-driven project to catalogue all jelly bean flavours released by Bertie Botts.</p>

        <form method="post" action="<?php echo $_SERVER['PHP_SELF'];?>" class="search-bar" >
            <input
                type="text"
                id="search"
                name="search"
                placeholder="Search ..."
                pattern="[a-zA-Z0-9 -]+"
                <?php if (!empty($_POST['search'])) { echo "value='" . $_POST['search'] . "'"; } ?>
                maxlength=16
            >
            <input type="submit" id="submit" value="Submit">
          </form>
    </div>
    <div class="row">
        <div class="bean-grid">

            <?php
                // Create connection
                $conn = new mysqli("db", $_ENV["DB_USERNAME"], $_ENV["DB_PASSWORD"], $_ENV["DB_DATABASE"]) or die("Connect failed: %s\n". $conn -> error);

                if ($_SERVER["REQUEST_METHOD"] == "POST") {
                    // collect value of input field
                    $keyword = $_POST['search'];
                    $search = "SELECT * FROM Beans WHERE bean_name LIKE '%$keyword%'";

                } else {
                    $search = "SELECT * FROM Beans";
                }

                $result = $conn->query($search);

                if ($result->num_rows > 0) {
                // output data of each row
                while($row = $result->fetch_assoc()) {
                    echo "<div class='bean-card'>
                            <div class='bean-image'>
                                <div class='bean-image-box'><img src='/beans/" . $row['icon'] . "' />
                            </div>
                        </div>
                        <div class='bean-desc'>
                            <h5>" . $row['bean_name'] . "</h5>
                            <i>" . $row['bean_edition'] . "</i>
                            <span>" . $row['bean_desc'] . "</span>
                        </div>
                    </div>";
                }
                } else {
                    echo "No results found.";
                }
                $conn->close();

                // if (empty($name)) {
                //     echo "Name is empty";
                // } else {
                //     echo $name;
                // }
            ?>
        </div>
    </div>
  </div>

<!-- End Document
  –––––––––––––––––––––––––––––––––––––––––––––––––– -->
</body>
</html>
