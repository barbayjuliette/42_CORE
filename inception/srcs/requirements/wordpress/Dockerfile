FROM debian:latest

RUN apt-get update && apt-get upgrade --yes && apt-get install -y php-fpm

COPY ./conf/www.conf etc/php/8.2/fpm/pool.d/www.conf

CMD ["php-fpm8.2", "-F"]