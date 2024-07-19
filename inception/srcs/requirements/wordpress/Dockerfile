# FROM debian:bullseye

# RUN apt-get update && apt-get upgrade --yes && apt-get install -y php7.4-fpm

# COPY ./conf/www.conf etc/php/7.4/fpm/pool.d/www.conf

# CMD ["php-fpm7.4", "-F"]

FROM debian:latest

RUN apt-get update && apt-get upgrade --yes && \ 
	apt-get install -y php-fpm php-mysql curl tar

# Create the target directory
RUN mkdir -p /var/www/html

# Download and install WordPress
RUN curl -O https://wordpress.org/latest.tar.gz && \
    tar -zxvf latest.tar.gz && \
    rm latest.tar.gz && \
    mv wordpress/* /var/www/html/ && \
    rmdir wordpress && \
    chown -R www-data:www-data /var/www/html && \
    chmod -R 755 /var/www/html

COPY ./conf/www.conf /etc/php/8.2/fpm/pool.d/www.conf
COPY ./conf/wp-config.php /var/www/html/wp-config.php

# Expose PHP-FPM port
EXPOSE 9000

CMD ["php-fpm8.2", "-F"]
