<?php
$title=$_POST['txt'];
$con=new
mysqli("localhost","fisat","fisat","fisatdb");
if($con==false)
{
echo "Failed to connect";
}
else
{
echo "connected\n";
}
$sql="select * from sample40 where
Title='$title'";
if($result=$con->query($sql))
{
if($result->num_rows>0)
{
while($row=$result->fetch_array())
{ echo "\n".$row[0].":".$row[1].":".$row[2].":".
$row[3].":".
$row[4]."\n";}
$result->close();
} else
{ echo "\nCould not found the book"; }
}
else
{ echo "\nError:could not connect"; }
$con->close();
?>
