I built this to fix my Dune-HD players file associations.
All of my files got stuck with a match to the same movie.
I flashed this to a WEMO S2 mini esp32 device.

This basically emulates the button presses of a keyboard/remote
and selects the correct match from the menus, contingent on it always being in the same spot.

Go to Setup>My Collection>Manage folders>"yourfolder">"C Movies from this folder"
then select the movie you need to change a bunch of matched files for
Then push Popup>View File in Filebrowser

Scroll down to the first file that doesn't match. 

Pushing button 0 on the S2 mini starts the sequence:

Selects "search association"
Go down to the second search result, which in my case was correct
Then commits the result
