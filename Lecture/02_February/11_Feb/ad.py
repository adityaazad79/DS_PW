import logging
logging.basicConfig(
                    level=logging.INFO,
                    format='%(asctime)s %(levelname)s %(message)s')
# logging.basicConfig(filename="sdfgfdgfd.log", level=logging.DEBUG)
# logging.basicConfig(filename="test.log", level=logging.INFO)
logging.info("This is my info logging")
logging.error("This is my error msg")
logging.critical("This is my critical")
u = "Aditya"
logging.critical("This is my %s",u)