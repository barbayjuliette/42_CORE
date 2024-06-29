FROM debian:bullseye

#  ! Update package manager
#  By default, Docker run as root: sudo is not needed
#  apt update it'll figure out what the latest version of each package and dependency is, but will not actually download or install any of those updates.
# The sudo apt-get upgrade command downloads and installs the updates for each outdated package and dependency on your system.

RUN apt-get update && apt-get upgrade --yes

# ! Install nginx
# ! Install openssl
# Openssl is an implementation of TLS and SSL. 
# Security protocol to establsih secure connection between 2 parties over the internet.
# The parties exchange encryption keys and digital certificate to establish secure connection
# The OpenSSL 1.1.1 release includes support for TLSv1.3. 
RUN apt-get install nginx openssl

# ! Create private key and certificate
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/nginx-selfsigned.key \
    -out /etc/ssl/certs/nginx-selfsigned.crt \
    -subj "/C=SG/L=Singapore/O=42Singapore/OU=student/CN=jbarbay.42.fr"

# req -x509L To generate a certificate. The option tells it to create self signed certificate
# -nodes : to not encrypt the key wioth passphrase. Usually neede in production
# newkey rsa:2048: create new key using RSA and size 2048 bits
# -subj: subject of the certificate. WHo it is for, what it is used for...

# After this, a self-signed SSL/TLS certificate and private key will be generated and stored in the specified files
# I can then use these files to configure an NGINX server to use SSL?TLS encrytion. 
# We do that in the nginx.conf file

# ! Copy NGINX configuration
# The COPY command in a Dockerfile copies files from your local machine into the Docker image. In this line:
# This copies the nginx.conf file from your local directory to /etc/nginx/nginx.conf inside the Docker image.
# You need to copy this file to customize NGINX’s configuration, such as enabling TLS protocols or setting server options.
COPY nginx.conf /etc/nginx/nginx.conf

# Port 443 is used for HTTPS traffic, which is HTTP over SSL/TLS.
EXPOSE 443

# !Start NGINX
#  start the Nginx web server in the foreground and to disable daemon mode
# daemon off;: This directive tells NGINX to run in the foreground (not as a background daemon). This is important in Docker containers to keep the container running and allow Docker to manage the process.
CMD ["nginx", "-g", "daemon off;"]