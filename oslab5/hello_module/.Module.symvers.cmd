cmd_/home/pupuhero/Desktop/OSlab/oslab5/hello_module/Module.symvers := sed 's/\.ko$$/\.o/' /home/pupuhero/Desktop/OSlab/oslab5/hello_module/modules.order | scripts/mod/modpost -m -a  -o /home/pupuhero/Desktop/OSlab/oslab5/hello_module/Module.symvers -e -i Module.symvers   -T -