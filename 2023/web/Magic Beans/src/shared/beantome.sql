CREATE DATABASE IF NOT EXISTS beantome;
USE beantome;

DROP TABLE IF EXISTS Beans;

CREATE TABLE Beans (
    bean_id      int AUTO_INCREMENT PRIMARY KEY NOT NULL,
    bean_name    VARCHAR(16) NOT NULL,
    bean_edition VARCHAR(16) NOT NULL,
    bean_desc    VARCHAR(96) NOT NULL,
    icon         VARCHAR(8) NOT NULL
);

DROP TABLE IF EXISTS Flag;

CREATE TABLE Flag (
    a   VARCHAR(1) NOT NULL PRIMARY KEY,
    b   VARCHAR(1) NOT NULL,
    c   VARCHAR(1) NOT NULL,
    d   VARCHAR(1) NOT NULL,
    e   VARCHAR(1) NOT NULL,
    f   VARCHAR(1) NOT NULL,
    g   VARCHAR(1) NOT NULL,
    h   INTEGER  NOT NULL,
    i   VARCHAR(1) NOT NULL,
    j   VARCHAR(1) NOT NULL,
    k   VARCHAR(1) NOT NULL,
    l   VARCHAR(1) NOT NULL,
    m   INTEGER  NOT NULL,
    n   INTEGER  NOT NULL,
    o   VARCHAR(1) NOT NULL,
    p   VARCHAR(1) NOT NULL,
    q   VARCHAR(1) NOT NULL,
    r   VARCHAR(1) NOT NULL,
    s   VARCHAR(1) NOT NULL,
    t   VARCHAR(1) NOT NULL,
    u   INTEGER  NOT NULL,
    v   VARCHAR(1) NOT NULL,
    w   VARCHAR(1) NOT NULL
);

INSERT INTO Flag(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w) VALUES ('q','u','a','c','k','{','J',3,'l','l','y','_',8,3,'l','l','y','_','r','u',5,'H','}');

INSERT INTO `Beans` VALUES (NULL, 'Berry Blue','Original','Tastes like food colouring.','1.png');
INSERT INTO `Beans` VALUES (NULL, 'Very Cherry','Original','This one will mess you up.','2.png');
INSERT INTO `Beans` VALUES (NULL, 'Strawberry','Original','99% sugar.','3.png');
INSERT INTO `Beans` VALUES (NULL, 'Blueberry','Original','This one is actually made from berries.','4.png');
INSERT INTO `Beans` VALUES (NULL, 'Orange','Original','Introduced after selling our entire stock of black beans.','5.png');
INSERT INTO `Beans` VALUES (NULL, 'Sour Apple','Original','What? Apples aren''t sour...','6.png');
INSERT INTO `Beans` VALUES (NULL, 'Tutti Frutti','Original','Apparently the most beloved bean.','7.png');
INSERT INTO `Beans` VALUES (NULL, 'Banana','Original','Finally, some good food!','8.png');
INSERT INTO `Beans` VALUES (NULL, 'Red','Original','It''s just got that red flavour.','9.png');
INSERT INTO `Beans` VALUES (NULL, 'Coffee','Original','Straight up just a coffee bean.','10.png');
INSERT INTO `Beans` VALUES (NULL, 'Black','Original','Put them in your burrito.','11.png');
INSERT INTO `Beans` VALUES (NULL, 'Green','Original','Good for the environment.','12.png');
INSERT INTO `Beans` VALUES (NULL, 'Milk','Original','Coagulated remnants of soy milk.','13.png');
INSERT INTO `Beans` VALUES (NULL, 'Baked','Original','All natural and deliciously rich.','14.png');
INSERT INTO `Beans` VALUES (NULL, 'Chickpea','Original','Also a legume.','15.png');
INSERT INTO `Beans` VALUES (NULL, 'Pickle','Basic','Indulge in that unmistakable tang.','16.png');
INSERT INTO `Beans` VALUES (NULL, 'Triangle','Basic','Really captures the flavour.','17.png');
INSERT INTO `Beans` VALUES (NULL, 'Avocado','Basic','Not to be confused with guacamole.','18.png');
INSERT INTO `Beans` VALUES (NULL, 'Apple','Basic','Crunchy and sweet.','19.png');
INSERT INTO `Beans` VALUES (NULL, 'Microsoft','Basic','Small and soft.','20.png');
INSERT INTO `Beans` VALUES (NULL, 'LinkedIn','Promotional','Corporate was very happy introducing this one into the range.','21.png');
INSERT INTO `Beans` VALUES (NULL, 'Brain Blaster™','Promotional','Tastes just like exam day.','22.png');
INSERT INTO `Beans` VALUES (NULL, 'McBean','Promotional','Tastes like a Cheese & Bacon McSpicy.','23.png');
INSERT INTO `Beans` VALUES (NULL, 'Mr Bean','Promotional','Likable, but slow-witted and challenging to digest.','24.png');
INSERT INTO `Beans` VALUES (NULL, 'Barbie','Promotional','A sweet sensation.','25.png');
INSERT INTO `Beans` VALUES (NULL, 'Oppenheimer','Promotional','Intended to be eaten in an IMAX theatre.','26.png');
INSERT INTO `Beans` VALUES (NULL, 'Boris Johnson','Gourmet','Bathed in other beans.','27.png');
INSERT INTO `Beans` VALUES (NULL, 'Oui Oui Baguette','Gourmet','Como te llamas, tu gusto es yum yum.','28.png');
INSERT INTO `Beans` VALUES (NULL, 'Crunchy Onion','Gourmet','Supple and soft.','29.png');
INSERT INTO `Beans` VALUES (NULL, 'Potassium','Gourmet','A healthy alternative.','30.png');
INSERT INTO `Beans` VALUES (NULL, 'Guacamole','Gourmet','Not to be confused with avocado. (Gluten free)','31.png');
INSERT INTO `Beans` VALUES (NULL, 'Toothpaste','Gourmet','Recommended by 9/10 dentists.','32.png');
INSERT INTO `Beans` VALUES (NULL, 'Red Herring','Gourmet','Very fishy.','33.png');
INSERT INTO `Beans` VALUES (NULL, '8-bit','Gourmet','▙  ▞▙▙▚▟▟ ▗▜▖ ▙▚▚▟  ▙▟▞▙▖ ▞▙▟▟▗','34.png');
INSERT INTO `Beans` VALUES (NULL, 'Indictment','Gourmet','Legend says that this bean will make your hair orange and your words nonsensical.','35.png');
INSERT INTO `Beans` VALUES (NULL, 'Jif','Assorted','Sometimes lemony and sometimes buttery.','36.png');
INSERT INTO `Beans` VALUES (NULL, 'Gif','Assorted','Tastes the way it looks and sounds the way it''s spelled.','37.png');
INSERT INTO `Beans` VALUES (NULL, 'Liquorice','Banned','Summons Horvath Auger of the Blood Field.','38.png');


CREATE USER 'baby'@'%' IDENTIFIED BY '<REDACTED>';
GRANT ALL PRIVILEGES ON beantome.* TO 'baby'@'%' WITH GRANT OPTION; -- should be read only
flush privileges;
