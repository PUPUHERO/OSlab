cmd_/home/pupuhero/Desktop/OSlab/oslab5/symbol/Module.symvers := sed 's/\.ko$$/\.o/' /home/pupuhero/Desktop/OSlab/oslab5/symbol/modules.order | scripts/mod/modpost -m -a  -o /home/pupuhero/Desktop/OSlab/oslab5/symbol/Module.symvers -e -i Module.symvers   -T -
