
public class MyRunnableTask implements Runnable {
	Args args;
	int size;
	
	public MyRunnableTask(Args args){
		this.args=args;
		this.size=args.getArr().length;
	}
	
	public void run() {
		int id=args.getId();
		for (int i = 1; i < size; i*=2) {
			try {
				args.getSem()[id].acquire();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			if(id-i>=0)
				args.getArr()[id]+=args.getArr()[id-i];
			if(id==0)
				args.getSem()[size-1].release();
			else
				args.getSem()[id-1].release();
		}
	}
}
