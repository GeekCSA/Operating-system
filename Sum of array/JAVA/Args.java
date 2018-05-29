import java.util.concurrent.Semaphore;

public class Args {
	private int id;
	private Semaphore[] sem;
	private int[] arr;
	/**
	 * Constructor.
	 * @param id
	 * @param sizeofarr
	 * @param a
	 * @param arr
	 */
	public Args(int id, Semaphore[] sem, int[] arr) {
		this.id = id;
		this.sem = sem;
		this.arr = arr;
	}
	/**
	 * @return the id
	 */
	public int getId() {
		return id;
	}

	/**
	 * @param id the id to set
	 */
	public void setId(int id) {
		this.id = id;
	}
	/**
	 * @return the a
	 */
	public Semaphore[] getSem() {
		return sem;
	}

	/**
	 * @param a the a to set
	 */
	public void setSem(Semaphore[] sem) {
		this.sem = sem;
	}

	/**
	 * @return the arr
	 */
	public int[] getArr() {
		return arr;
	}

	/**
	 * @param arr the arr to set
	 */
	public void setArr(int[] arr) {
		this.arr = arr;
	}


	
}
