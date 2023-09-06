package com.codility.lessons.StacksQueues;

import org.junit.After;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Rule;
import org.junit.Test;
import org.junit.rules.Timeout;
import org.junit.runner.RunWith;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.test.context.junit4.SpringRunner;

import com.codility.lessons.CountingElements.PermutationCheckTest;

@RunWith(SpringRunner.class)
public class StoneWallTest {

	private static Logger LOG = LoggerFactory.getLogger(PermutationCheckTest.class);

	static StoneWall stoneWall;

	@Rule
	public Timeout globalTimeout = Timeout.seconds(1);

	@BeforeClass
	public static void setup() {
		stoneWall = new StoneWall();
	}

	static long start, end;
	static double diff;

	@Before
	public void start() {
		start = System.currentTimeMillis();
		LOG.info("start-->" + start);
	}

	@After
	public void end() {
		end = System.currentTimeMillis();
		LOG.info("end-->" + end);

		diff = end - start;
		LOG.info("millis-->" + (diff));// millis
		LOG.info("seconds-->" + (diff / 1000));// seconds
	}

	@Test
	public void solution1Test() {

		// int res = stoneWall.solution1( );
		// assertEquals(res, 1);
	}
}
