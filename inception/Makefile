DOCKER_COMPOSE_FILE= ./srcs/docker-compose.yml
WP_DATA="/home/jbarbay/data/wordpress"
DB_DATA="/home/jbarbay/data/wordpress"
RM = rm -rf

up:
	mkdir -p $(WP_DATA)
	mkdir -p $(DB_DATA)
	docker-compose -f $(DOCKER_COMPOSE_FILE) up --build -d


# Stop the containers without removing them
stop:
	docker-compose -f $(DOCKER_COMPOSE_FILE) stop

# Restart the containers
start:
	docker-compose -f $(DOCKER_COMPOSE_FILE) start

# Stop and remove the containers
down:
	docker-compose -f $(DOCKER_COMPOSE_FILE) down

# Delete containers with data
clean:
	docker rm $$(docker ps -qa) || true
	docker rmi -f $$(docker images -a -q) || true
	docker-compose -f $(DOCKER_COMPOSE_FILE) down --volumes || true
	docker network rm inception || true
	$(RM) $(WP_DATA) || true
	$(RM) $(DB_DATA) || true

re: clean up

.PHONY: all clean re up stop start down