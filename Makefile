MAKE = make -C

all:
	$(MAKE) ./generator
	$(MAKE) ./depth
	$(MAKE) ./breadth
	$(MAKE) ./astar
	$(MAKE) ./tournament

clean:
	$(MAKE) ./generator clean
	$(MAKE) ./depth clean
	$(MAKE) ./breadth clean
	$(MAKE) ./astar clean
	$(MAKE) ./tournament clean

fclean:
	$(MAKE) ./generator fclean
	$(MAKE) ./depth fclean
	$(MAKE) ./breadth fclean
	$(MAKE) ./astar fclean
	$(MAKE) ./tournament fclean

re: fclean all
