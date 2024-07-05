
# MariaDB will be the database to store information 
# about our wordpress users and settings.
# We have to create the Mariadb image and create 2 users.

FROM debian:bullseye

RUN apt-get update && apt-get upgrade --yes

RUN apt-get install -y mariadb-server