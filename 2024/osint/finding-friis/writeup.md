# Finding Friis
**Category**: Osint
**Author**: Will
**Difficulty**: Hard (500pts)

### Description
I got kidnapped by a cyber duck and the gps on my phone is broken :(.
Can you find my location from my transmissions with these cell towers?

Flag format: quack{location_name}

### Solution
Use the cellphone tower ID's and other info provided to locate the coordinates of each cell tower from a site such as https://opencellid.org/.

Once the coordinates of the towers are known, use the friis transmission formula and the signal strengths, gain etc to calculate the range from each tower to the phone. This can be done by hand or with a calculator like https://www.random-science-tools.com/electronics/friis.htm.

With the location of each tower and the distance to the phone known, three circles can be plotted on a map. These circles should have their centre on the cell towers and their radius set to the tower's respective range. Once the circles are plotted, they should all intersect in one position, giving the final location.
