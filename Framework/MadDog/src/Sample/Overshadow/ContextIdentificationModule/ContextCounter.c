#include "ContextCounter.h"

//extern PHYSICAL_ADDRESS g_PageMapBasePhysicalAddress;
//extern BOOLEAN g_bDisableComOutput;

static MadDog_Control md_Control = 
{
	NULL,
	NULL,
	&HvmSetupVMControlBlock,
	&VmxRegisterTraps
};

NTSTATUS DriverUnload (
    PDRIVER_OBJECT DriverObject
)
{
    //FIXME: do not turn SVM/VMX when it has been turned on by the guest in the meantime (e.g. VPC, VMWare)
    NTSTATUS Status;

    Print(("\r\n"));
    Print(("NEWBLUEPILL: Unloading started\n"));

    if (!NT_SUCCESS (Status = MadDog_UninstallHypervisor())) 
    {
        Print(("NEWBLUEPILL: UninstallHypervisor() failed with status 0x%08hX\n",Status));
		PrintInfoDispose();
        return Status;
    }

    Print(("NEWBLUEPILL: Unloading finished\n"));

	PrintInfoDispose();
    return STATUS_SUCCESS;
}

NTSTATUS DriverEntry (
    PDRIVER_OBJECT DriverObject,
    PUNICODE_STRING RegistryPath
)
{
    NTSTATUS Status;
    //CmDebugBreak();
   // ULONG ulOldCR3;

    PrintInfoInit();
	Print(("Hello world!"));
    //__asm { int 3 }

    // test for our pagetabel
    //__asm 
    //{
    //    mov eax, cr3
    //    mov ulOldCR3, eax
    //    mov eax, g_PageMapBasePhysicalAddress.LowPart
    //    mov cr3, eax
    //}


    if (!NT_SUCCESS (Status = MadDog_HypervisorInit())) 
    {
        Print(("HELLOWORLD: HypervisorInit() failed with status 0x%08hX\n", Status));
		PrintInfoDispose();
		return Status;
    }
	Print(("HELLOWORLD: Successful in execute HvmInit()"));


    if (!NT_SUCCESS (Status = MadDog_InstallHypervisor(&md_Control))) //<------------------1 Finish
    {
        Print(("HELLOWORLD: InstallHypervisor() failed with status 0x%08hX\n", Status));
		PrintInfoDispose();
		return Status;
    }
//
//    // vt is on
//    // make all the kernel memory not writable
//    // MmProtectKernelMemory();
//
      DriverObject->DriverUnload = DriverUnload;
//
		Print(("HELLOWORLD: Initialization finished\n"));
	#if DEBUG_LEVEL>1
		Print(("HELLOWORLD: EFLAGS = %#x\n", RegGetRflags ()));
	#endif
////
////    //__asm
////    //{
////    //    mov eax, ulOldCR3
////    //    mov cr3, eax
////    //}
////
    return STATUS_SUCCESS;
}
