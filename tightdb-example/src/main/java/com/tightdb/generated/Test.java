/* This file was automatically generated by TightDB. */

package com.tightdb.generated;


import com.tightdb.*;
import com.tightdb.lib.*;

/**
 * This class represents a TightDB cursor and was automatically generated.
 */
public class Test extends AbstractCursor<Test> {

    public final LongCursorColumn<Test, TestView, TestQuery> indexInt;
    public final StringCursorColumn<Test, TestView, TestQuery> second;
    public final LongCursorColumn<Test, TestView, TestQuery> byteInt;
    public final LongCursorColumn<Test, TestView, TestQuery> smallInt;
    public final LongCursorColumn<Test, TestView, TestQuery> longInt;

	public Test(IRowsetBase rowset, long position) {
		super(TestTable.TYPES, rowset, position);

        indexInt = new LongCursorColumn<Test, TestView, TestQuery>(TestTable.TYPES, this, 0, "indexInt");
        second = new StringCursorColumn<Test, TestView, TestQuery>(TestTable.TYPES, this, 1, "second");
        byteInt = new LongCursorColumn<Test, TestView, TestQuery>(TestTable.TYPES, this, 2, "byteInt");
        smallInt = new LongCursorColumn<Test, TestView, TestQuery>(TestTable.TYPES, this, 3, "smallInt");
        longInt = new LongCursorColumn<Test, TestView, TestQuery>(TestTable.TYPES, this, 4, "longInt");
	}

	public long getIndexInt() {
		return this.indexInt.get();
	}

	public void setIndexInt(long indexInt) {
		this.indexInt.set(indexInt);
	}

	public java.lang.String getSecond() {
		return this.second.get();
	}

	public void setSecond(java.lang.String second) {
		this.second.set(second);
	}

	public long getByteInt() {
		return this.byteInt.get();
	}

	public void setByteInt(long byteInt) {
		this.byteInt.set(byteInt);
	}

	public long getSmallInt() {
		return this.smallInt.get();
	}

	public void setSmallInt(long smallInt) {
		this.smallInt.set(smallInt);
	}

	public long getLongInt() {
		return this.longInt.get();
	}

	public void setLongInt(long longInt) {
		this.longInt.set(longInt);
	}

	@Override
	public AbstractColumn<?, ?, ?, ?>[] columns() {
		return getColumnsArray(indexInt, second, byteInt, smallInt, longInt);
	}

}