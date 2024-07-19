
# MariaDB will be the database to store information 
# about our wordpress users and settings.
# We have to create the Mariadb image and create 2 users.

FROM debian:bullseye

RUN apt-get update && apt-get upgrade --yes && \
	apt-get install -y mariadb-server

RUN mkdir -p /run/mysqld && chown mysql:mysql /run/mysqld

COPY 50-server.cnf /etc/mysql/mariadb.conf.d/.
COPY init.sql /etc/mysql/init.sql

EXPOSE 3306

CMD ["mysqld"]